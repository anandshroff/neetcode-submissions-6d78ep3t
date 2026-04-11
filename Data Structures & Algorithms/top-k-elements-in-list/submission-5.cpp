class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>count;

        for(int i=0;i<nums.size();i++)
        {
            count[nums[i]]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>minHeap;

        for(auto &it: count)
        {
            minHeap.push({it.second, it.first});
            if(minHeap.size() > k)
                minHeap.pop();
        }

        vector<int>res;
        for(int i=0; i<k; i++)
        {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return res;
    }
};
