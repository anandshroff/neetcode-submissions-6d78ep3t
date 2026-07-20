class Solution {
    vector<vector<int>> ans;
    vector<int> curr;
    vector<bool> used;

    void solve(vector<int>& nums) {

        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            if (used[i])
                continue;

            used[i] = true;
            curr.push_back(nums[i]);

            solve(nums);

            curr.pop_back();
            used[i] = false;
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        used.assign(nums.size(), false);
        solve(nums);
        return ans;
    }
};
