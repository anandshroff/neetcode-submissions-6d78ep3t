class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>result;
        int mult=nums[0];
        int has_zero = 0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] != 0)
                mult = mult * nums[i];
            else
                has_zero++; 
        }
        if(has_zero>1)
        {
            for(int i=0;i<nums.size();i++)
            {
                result.push_back(0);
            }
            return result;
        }
        if(has_zero==1)
        {
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i] == 0)
                    result.push_back(mult);
                else
                    result.push_back(0);
            }
            return result;
        }
        int div;
        for(int i=0;i<nums.size();i++)
        {   
            if(nums[i] != 0){ 
                div = mult/nums[i];
                result.push_back(div);
            }
        }
        
        return result;
    }
};
