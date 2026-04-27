class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;

        for(int i = 0; i < tokens.size(); i++)
        {
            if(tokens[i] == "+" || tokens[i] == "*" ||
               tokens[i] == "/" || tokens[i] == "-"    )
               {
                    int x, y, res;
                    if(!st.empty())
                    {
                        y = st.top();
                        st.pop();
                        x = st.top();
                        st.pop();
                    }
                    if(tokens[i] == "+")
                    {
                        res = x + y;
                        st.push(res);
                    }
                    else if(tokens[i] == "-")
                    {
                        res = x-y;
                        st.push(res);
                    }
                    else if(tokens[i] == "*")
                    {
                        res = x*y;
                        st.push(res);
                    }
                    else{
                        res = x/y;
                        st.push(res);
                    }
               }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
