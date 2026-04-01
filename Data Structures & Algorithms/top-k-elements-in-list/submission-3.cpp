class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>count;
        for(int i=0;i<nums.size();i++)
        {
            count[nums[i]]++;
        }
        vector<pair<int,int>>vec;
        vector<int>result;
        for(const auto &i:count)
        {
            vec.push_back({i.second, i.first});
        }
        sort(vec.rbegin(), vec.rend());

        for(int i=0;i<k;i++)
        {
            result.push_back(vec[i].second);
        }
        return result;
    }
};
