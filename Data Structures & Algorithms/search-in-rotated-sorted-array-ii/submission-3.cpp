class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size()-1;

        while(l<=h){
            int m = l + (h-l)/2;
            
            if(nums[m] == target)
                return true;
            if(nums[m] == nums[l] && nums[m] == nums[h]){
                l++;
                h--;
            }
            else if(nums[l] <= nums[m]){
                if(nums[m] > target && nums[l] <= target)
                    h = m-1;
                else
                    l = m+1;
            }
            else if(nums[h] >= nums[m]){
                if(nums[m] < target && nums[h] >= target)
                    l = m+1;
                else
                    h = m-1;
            }
            
        }
        return false;
    }
};