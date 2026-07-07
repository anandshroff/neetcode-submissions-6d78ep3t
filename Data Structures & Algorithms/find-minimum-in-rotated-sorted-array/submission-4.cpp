class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int h = nums.size()-1;
        int smallest = INT_MAX;

        while(l<=h){
            if(nums[l] < nums[h]){
                smallest = min(smallest, nums[l]);
                return smallest;
            }
            int m = l + (h-l)/2;
            smallest = min(smallest, nums[m]);

            if(nums[m] >= nums[l]){
                l = m+1;
            }
            else{
                h = m-1;
            }
        }
        return smallest;
    }
};
