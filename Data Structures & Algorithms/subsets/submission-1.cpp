class Solution {
    vector<vector<int>>ans;
    void findSubsets(int idx, vector<int> &nums, vector<int>&currSet){
        if(idx == nums.size()){
            ans.push_back(currSet);
            return;
        }
        currSet.push_back(nums[idx]);
        findSubsets(idx+1, nums, currSet);
        currSet.pop_back();
        findSubsets(idx+1, nums, currSet);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>currSet;
        findSubsets(0, nums, currSet);
        return ans;
    }
};
