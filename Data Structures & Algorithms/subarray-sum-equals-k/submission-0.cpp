class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        mp[0] = 1;
        int ans = 0;
        int currS = 0;

        for(auto num: nums){
            currS = currS + num;
            int d = currS - k;
            if(mp.find(d) != mp.end()){
                ans = ans + mp[d];
            }
            mp[currS]++;
        }
        return ans;
    }
};