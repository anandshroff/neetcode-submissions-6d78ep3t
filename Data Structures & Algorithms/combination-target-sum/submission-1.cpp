class Solution {
    void uniqueComb(int idx, vector<int>& nums, int target, vector<vector<int>>&ans, vector<int>&curr){

        if(target == 0){
            ans.push_back(curr);
            return;
        }
        if(idx == nums.size() || target < 0){
            return;
        }
        //take
        if(nums[idx]<=target){
            curr.push_back(nums[idx]);
            uniqueComb(idx, nums, target - nums[idx], ans, curr);
            curr.pop_back();
        }
        //don't take
        uniqueComb(idx+1, nums, target, ans, curr);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>curr;

        uniqueComb(0, nums, target, ans, curr);
        return ans;
    }
};
