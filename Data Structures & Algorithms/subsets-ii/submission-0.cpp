class Solution {
    void findSubset(int idx, vector<int>&nums, vector<vector<int>>&ans,
                        vector<int> &curr){
        
        ans.push_back(curr);

        for(int i = idx; i<nums.size(); i++){
            if(i>idx && nums[i] == nums[i-1]) continue;
            curr.push_back(nums[i]);
            findSubset(i+1, nums, ans, curr);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        sort(nums.begin(), nums.end());
        findSubset(0, nums, ans, curr);
        return ans;
    }
};
