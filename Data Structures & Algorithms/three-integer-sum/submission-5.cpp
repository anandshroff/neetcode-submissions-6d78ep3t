class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        
        for(int l = 0; l<n-2; l++){
            if(nums[l] > 0) break;

            if(l > 0 && nums[l] == nums[l-1]) continue;

            int m = l+1;
            int r = n-1;

            while(m<r){
                int sum = nums[l] + nums[m] + nums[r];

                if(sum == 0){
                    ans.push_back({nums[l], nums[m], nums[r]});

                    while(m<r && nums[m] == nums[m+1])
                        m++;
                    
                    while(m<r && nums[r] == nums[r-1])
                        r--;
                    
                    m++;
                    r--;
                }
                else if(sum > 0)
                    r--;
                else
                    m++;
            }
        }
        return ans;
    }
};
