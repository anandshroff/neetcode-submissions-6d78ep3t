class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int res = nums[0];

        for(auto it = 1; it<nums.size(); it++){
            res = res^nums[it];
        }
        return res;
    }
};
