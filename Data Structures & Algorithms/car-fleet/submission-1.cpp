class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>nums;
        for(int i = 0; i < position.size(); i++)
        {
            nums.push_back({position[i], speed[i]});
        }

        sort(nums.rbegin(), nums.rend());

        double prevTime;
        prevTime = (double)(target - nums[0].first)/nums[0].second;
        int fleet = 1;
        for(int i = 1; i<position.size(); i++)
        {
            double currTime = (double)(target - nums[i].first) / nums[i].second;
            if(currTime > prevTime)
            {
                fleet++;
                prevTime = currTime;
            }
        }
        return fleet;
    }
};
