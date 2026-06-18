class Solution {
    vector<vector<int>>ans;
    void generateSubsets(int idx, vector<int>&nums, vector<int> sets){
        if(idx == nums.size()){
            ans.push_back(sets);
            return;
        }

        sets.push_back(nums[idx]);
        generateSubsets(idx+1, nums, sets);
        sets.pop_back();
        generateSubsets(idx+1, nums, sets);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int>sets;
        generateSubsets(0, nums, sets);
        return ans;
    }
};
