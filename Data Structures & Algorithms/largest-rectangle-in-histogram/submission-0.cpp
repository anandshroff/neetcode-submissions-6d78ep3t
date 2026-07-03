class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int nse, pse;
        stack<int>st;
        int area = 0;

        for(int i = 0; i<heights.size();i++){
            while(!st.empty() && heights[i] <= heights[st.top()]){
                int top = st.top();
                st.pop();
                nse = i;
                pse = st.empty()? -1 : st.top();
                area = max(area, heights[top]*(nse - pse - 1));
            }
            st.push(i);
        }

        while(!st.empty()){
            nse = heights.size();
            int top = st.top();
            st.pop();
            pse = st.empty()? -1 : st.top();

            area = max(area, heights[top]*(nse - pse - 1));
        }
        return area;
    }
};
