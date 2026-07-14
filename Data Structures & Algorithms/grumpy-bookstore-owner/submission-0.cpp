class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int l = 0;
        int satisfied = 0;
        int baseSum = 0;
        int extraSum = 0;
        int sum = 0;
        if(customers.size() == 1)
            return customers[0];

        for(int i=0;i<customers.size();i++){
            if(!grumpy[i]){
                baseSum += customers[i];
            }
        }

        for(int r=0;r<customers.size();r++){
            if(grumpy[r]) sum += customers[r];

            if(r-l+1 > minutes){
                if(grumpy[l])
                    sum -= customers[l];
                l++;
            }

            if(r-l+1 == minutes){
                extraSum = max(extraSum, sum);
            }
        }
        return baseSum + extraSum;
    }
};