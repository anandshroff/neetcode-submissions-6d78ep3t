class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int>fc1;
        unordered_map<char, int>fc2;

        for(int i=0; i<s.size();i++){
            fc1[s[i]]++;
            
        }

        for(int i=0; i<t.size();i++){
            fc2[t[i]]++;
        }
        if(fc1 == fc2)
            return true;
        
        return false;
    }
};
