class Solution {
    void findSum(int idx, vector<int> &nums, vector<int>&curr, vector<vector<int>>&ans,
                    int target){
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        
        
        for(int i = idx; i<nums.size(); i++){
            if(i>idx && nums[i] == nums[i-1]) continue;
            if(nums[i] > target) break;
            curr.push_back(nums[i]);
            findSum(i+1, nums, curr, ans, target - nums[i]);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        sort(nums.begin(), nums.end());
        findSum(0, nums, curr, ans, target );
        return ans;
    }
};
