class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int h = accumulate(weights.begin(), weights.end(), 0);
        int least = INT_MAX;
        
        while(l<=h){
            int d = 1;
            int m = l + (h-l)/2;
            int sum = 0;
            for(auto w: weights){
                if(sum+w <= m){
                    sum += w;
                }
                else{
                    d++;
                    sum = w;
                }
                if(d > days) break;
            }
            if(d<=days){
                least = min(least, m);
                h = m-1;
            }
            else{
                l = m+1;
            }
        }
    return least;
    }
};