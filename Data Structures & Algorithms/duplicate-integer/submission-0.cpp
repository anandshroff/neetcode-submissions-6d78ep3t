class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]++;
        }

        for (auto i:mpp)
        {
            if(i.second > 1)
            return true;
        }
        return false;
    }
};