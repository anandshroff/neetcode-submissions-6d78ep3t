class Solution {
    vector<vector<int>>ans;
    vector<int>curr;
    vector<bool>used;
    void permutations(vector<int>&nums){
        if(curr.size() == nums.size()){
            ans.push_back(curr);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(used[i]) continue;
            if(i>0 && nums[i] == nums[i-1] && !used[i-1]) continue;
            used[i] = true;
            curr.push_back(nums[i]);
            permutations(nums);
            curr.pop_back();
            used[i] = false;
            
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        used.assign(nums.size(), false);
        permutations(nums);
        return ans;
    }
};