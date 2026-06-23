class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>need(256, 0);
        int minL = INT_MAX;
        int req = t.size();
        int l = 0;
        int start = 0;
        //make frequency table for t
        for(char i:t)
            need[i]++;

        for(int r = 0; r<s.size(); r++){
            char c = s[r];
            // If this character is still needed,
           // we have satisfied one required character
            if(need[c] > 0)
                req--;
            // Include current character in window
            need[c]--;

            // If req becomes 0, current window is valid
            while(req == 0){
                // Update minimum window if current one is smaller
                if(r-l+1 < minL){
                    minL = r-l+1;
                    start = l;
                }
                // Try shrinking the window from left
                char ch = s[l];

                // Remove left character from window
                need[ch]++;

                // If need[ch] becomes positive,
                // we have removed a required character
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
