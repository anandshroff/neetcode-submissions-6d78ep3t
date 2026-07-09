class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int hi) {
        int l = 1;
        int h = *max_element(piles.begin(), piles.end());
        int res = h;
        while(l<=h){
            int m = l + (h-l)/2;

            long long sum = 0;
            for(auto nums:piles){
                sum += (nums + m - 1) / m;
                if (sum > hi)
                    break;
            }
            if(sum <= hi){ 
                res = m;
                h = m-1;
            }
            else{
                l = m+1;
            }
        }
        return res;
    }
};
