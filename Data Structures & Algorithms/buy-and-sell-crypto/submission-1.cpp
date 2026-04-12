class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int sum = 0;
        int i, j;
        i = 0; j = 1;

        while(j<prices.size())
        {
            if(prices[i] > prices[j] )
            {
                i = j;
                j++;

            }
            else{
                
                    sum = prices[j] - prices[i];
                    j++; 
            }
            maxProfit = max(sum, maxProfit);
        }
        return maxProfit;
    }
};
