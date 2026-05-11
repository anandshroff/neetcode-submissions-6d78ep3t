class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int>st;
        for(int i = 0; i<ops.size(); i++){
            if(ops[i] == "+" && !st.empty()){
                int top = st.top();
                st.pop();
                int sTop;
                if(!st.empty()){
                    sTop = st.top();
                    int sum = top+sTop;
                    st.push(top);
                    st.push(sum);
                }
                else{ 
                    st.push(top);
                }
            }
            else if(ops[i] == "D"){
                if(!st.empty()){ 
                    int d = 2 * st.top();
                    st.push(d);
                }
            }
            else if(ops[i] == "C"){
                st.pop();
            }
            else{
                st.push(stoi(ops[i]));
            }
        }
        int ans = 0;
        while(!st.empty()){
            ans = ans + st.top();
            st.pop();
        }
        return ans;
    }
};