class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       int l = 0;
        vector<int>hsh1(26,0);
        vector<int>hsh2(26,0);
        int k = s1.size();
        for(int i=0; i<k; i++){
            hsh1[s1[i] - 'a']++;
        }

        for(int r=0; r<s2.size();r++){
            hsh2[s2[r] - 'a']++;

            if(r-l+1 > k){
                hsh2[s2[l] - 'a']--;
                l++;
            }

            if(r-l+1 == k){
                if(hsh1 == hsh2)
                    return true;
            }
        }
        
        return false;
    }
};
