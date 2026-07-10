class Solution {
public:
    struct compare{
        bool operator()(pair<int, int>&a, pair<int, int>&b){
            if(a.first != b.first)
                return a.first < b.first;

            return a.second < b.second;
        }
    };
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, compare>pq;
        vector<int>ans;

        for(int i=0;i<arr.size();i++){
            int val = abs(x-arr[i]);
            pq.push({val, arr[i]});

            if(pq.size() > k)
                pq.pop();
        }
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};