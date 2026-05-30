class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>sim(stones.begin(), stones.end());

        int max, secMax;

        while(sim.size() > 1){
            max = sim.top();
            sim.pop();
            secMax = sim.top();
            sim.pop();
            if(max == secMax) continue;
            else{
                int w = abs(max - secMax);
                sim.push(w);
            }
        }
        return sim.size() == 1?sim.top():0;
    }
};
