class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        

        sort(nums.begin(), nums.end());

        for (int l = 0; l < nums.size(); l++)
        {
            if(nums[l] > 0) break;
            if(l>0 && nums[l] == nums[l-1]) continue;
            int m = l+1;
            int r = nums.size()-1;
            while(m<r)
            { 
                if(nums[l] + nums[m] + nums[r] < 0)
                {
                    m++;
                }
                else if(nums[l] + nums[m] + nums[r] > 0)
                {
                    r--;
                }
                else{
                    res.push_back({nums[l],nums[m],nums[r]});
                    m++;
                    r--;
                    while(m<r && nums[m] == nums[m-1]){
                        m++;
                    }
                }
            }
            
        }
        return res;
    }
};
