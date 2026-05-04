class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string str = strs[0];

        for(int i=1;i<strs.size();i++){
            int j=0;
            string t = strs[i];
            while(j <= min(t.size(), str.size())){
                if(t[j] != str[j]){
                    break;
                }
                j++;
            }
            str = str.substr(0,j);
        }
        return str;
    }
};