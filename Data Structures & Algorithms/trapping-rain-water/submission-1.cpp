class Solution {
public:
    int trap(vector<int>& height) {
        stack<int>st;
        int res = 0;

        for(int i = 0; i<height.size();i++)
        {
            while(!st.empty() && height[st.top()] < height[i])
            {
                int prev = height[st.top()];
                st.pop();
                if(st.empty()) break;
                int distance = i - st.top() - 1;

                int water = min(height[st.top()], height[i]) - prev;
                res += water * distance;
            }
            st.push(i);
        }
        
        return res;
    }
};
