class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int>mp;
        int n = nums.size();
        int i=0;
        for(auto it = nums.begin(); it != nums.end(); ){
            if(mp.find(*it) != mp.end()){
                nums.erase(it);
            }
            else{
                mp[*it]++;
                it++;
            }
            
        }
        return nums.size();
    }
};