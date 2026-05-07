class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = 0;
        int n = nums.size();
        int val = 0;
        for(int i=0;i<n;i++){
            if(maj == 0)
             val = nums[i];
            if(nums[i] != val){
                maj--;
            }
            else{
                maj++;
            }
        }
        return val;
    }
};