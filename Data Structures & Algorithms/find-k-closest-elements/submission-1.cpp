class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;

        for(int i=0;i<arr.size();i++){
            int val = abs(x-arr[i]);
            pq.push({val, i});
        }
        vector<int>ans;
        while(!pq.empty() && k--){
            auto [val, idx] = pq.top();
            pq.pop();
            ans.push_back(arr[idx]);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};