class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mpp;    
        int diff;
        vector<int>result;
        for(int i=0;i<nums.size();i++)
        {
            diff = target- nums[i] ;
            if(mpp.find(diff) != mpp.end()){
                return {mpp[diff],i};
            }
            else
                mpp.insert({nums[i], i});
        }
        return {};
        
    }
};
