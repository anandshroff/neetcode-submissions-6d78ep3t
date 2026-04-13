class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int l = 0;
        vector<int>hash(256, -1);

        for(int r=0;r<s.length();r++)
        {
            if(hash[s[r]] != -1)
            {
                l = max(hash[s[r]]+1, l);
            }
            hash[s[r]] = r;
            maxLen = max(maxLen, r-l+1);
        }
        return maxLen;
    }
};
