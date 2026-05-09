class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l = 0,  r = 0;
        string res;
        if(word1 == "") return word2;
        if(word2 == "") return word1;
         while(l<word1.size() && r<word2.size()){
            res = res + word1[l++] + word2[r++];
         }

         while(l < word1.size()){
            res += word1[l++];
         }

         while(r < word2.size()){
            res += word2[r++];
         }

         return res;
    }
};