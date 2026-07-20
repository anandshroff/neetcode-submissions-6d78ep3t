class Solution {
    void permutations(int idx, vector<int>&nums, vector<vector<int>>&ans){
        if(idx == nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i=idx; i<nums.size(); i++){
            swap(nums[i], nums[idx]);
            permutations(idx+1, nums, ans);
            swap(nums[i], nums[idx]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;

        permutations(0, nums, ans);

        return ans;
    }
};
