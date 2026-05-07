class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int>mp;
        int maj;
        int maxi = 0;
        for(auto it:nums){
            mp[it]++;
        }
        for(auto it:mp){
            if(maxi < it.second){
                maxi = it.second;
                maj = it.first;
            }
                
        }
        return maj;
    }
};