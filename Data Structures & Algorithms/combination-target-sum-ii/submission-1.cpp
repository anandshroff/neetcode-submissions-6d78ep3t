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
        findSum(idx+1, nums, curr, ans, target - nums[idx] );
        curr.pop_back();

        int next = idx + 1;
        while(next < nums.size() && nums[next] == nums[idx])
            next++;
        
        findSum(next, nums, curr, ans, target );
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
