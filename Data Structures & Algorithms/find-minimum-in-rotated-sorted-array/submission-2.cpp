class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0;
        int r=nums.size()-1;
        int smallest = nums[0];
        while(l<=r)
        {
            if (nums[l] < nums[r]) {
                smallest = min(smallest, nums[l]);
                break;
            }
            int m = l + (r-l)/2;
            smallest = min(smallest, nums[m]);
            
            if(nums[m]>=nums[l])
            {
                
                l = m+1;
            }
            else{
                
                r = m-1;
            }
        }
        return smallest;
    }
};
