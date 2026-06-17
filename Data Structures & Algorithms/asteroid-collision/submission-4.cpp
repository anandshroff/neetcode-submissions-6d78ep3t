class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>st;

        for(auto it: asteroids){
            int destroyed = false;
            while(!st.empty() && st.back() > 0 && it < 0){
                if(st.back() < -it){
                    st.pop_back();
                }
                else if(st.back() == -it){
                    st.pop_back();
                    destroyed = true;
                    break;
                }
                else{
                    destroyed = true;
                    break;
                }
            }
            if(!destroyed){
                st.push_back(it);
            }
        }
        return st;   
    }
};