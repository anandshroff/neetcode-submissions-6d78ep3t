class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l, r;
        int sum = 0;
        int minL = INT_MAX;
        l = 0;
        r = 0;

        while(r<nums.size()){
            sum = sum + nums[r];
       
                while(target <= sum){
                    minL = min(minL, r-l+1);
                    sum = sum - nums[l];
                    l++;
                }
            r++;
        }
        return minL>nums.size()?0:minL;
    }
};