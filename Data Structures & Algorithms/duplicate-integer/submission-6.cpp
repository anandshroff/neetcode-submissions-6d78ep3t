class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int>exist;

        for(auto i:nums){
            if(exist.count(i)){
                return true;
            }
            else{
                exist.insert(i);
            }
        }
        return false;
    }
};