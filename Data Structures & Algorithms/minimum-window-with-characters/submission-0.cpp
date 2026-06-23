class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>need(256, 0);
        int minL = INT_MAX;
        int req = t.size();
        int l = 0;
        int start = 0;
        for(char i:t)
            need[i]++;

        for(int r = 0; r<s.size(); r++){
            char c = s[r];
            if(need[c] > 0)
                req--;
            
            need[c]--;

            while(req == 0){
                if(r-l+1 < minL){
                    minL = r-l+1;
                    start = l;
                }
                char ch = s[l];
                need[ch]++;

                if(need[ch] > 0)
                    req++;
                
                l++;
            }
        }
        return minL == INT_MAX ?
               "" : 
               s.substr(start, minL);
    }
};
