class Solution {
    void findSum(int idx, vector<int> &nums, vector<int>&curr, vector<vector<int>>&ans,
                    int target){
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        if(target < 0 || idx == nums.size()){
            return;
        }

        curr.push_back(nums[idx]);
        findSum(idx, nums, curr, ans, target - nums[idx] );
        curr.pop_back();
        findSum(idx+1, nums, curr, ans, target );
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>curr;

        findSum(0, nums, curr, ans, target );
        return ans;
    }
};
