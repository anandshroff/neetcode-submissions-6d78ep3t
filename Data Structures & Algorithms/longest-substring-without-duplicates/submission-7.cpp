class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        vector<int>rep(256,-1);
        int longSub = 0;

        for(int r=0; r<s.size(); r++){
            if(rep[s[r]] != -1){ 
                l = max(l, rep[s[r]]+1);
            }
            rep[s[r]] = r;
            longSub = max(longSub, r-l+1);
        }
        return longSub;
    }
};
