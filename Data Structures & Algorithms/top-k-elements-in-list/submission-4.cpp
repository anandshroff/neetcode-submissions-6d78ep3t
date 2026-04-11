class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>count;

        for(int i=0;i<nums.size();i++)
        {
            count[nums[i]]++;
        }

        vector<vector<int>>buck(nums.size()+1);
        for(auto &it: count)
        {
            buck[it.second].push_back(it.first);
        }

        vector<int>result;
        for(int i = buck.size()-1; i>0; i--)
        {
            for(auto &it: buck[i])
            {
                result.push_back(it);
                if(result.size() == k)
                    return result;
            }
        }
        return result;
    }
};
