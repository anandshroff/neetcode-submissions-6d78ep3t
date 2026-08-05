class Solution {
public:
    bool isHappy(int n) {
        int sum = 0;
        int div, rem, x = n;
        set<int>s;

        while(1){
            while(x){
                rem = x%10;
                sum = sum + (rem*rem);
                x = x/10;
            }
            if(sum == 1)
            {
                return true;
            }
            if(!s.count(sum)){ 
                s.insert(sum);
                x = sum;
                sum = 0;
            }
            else
                break;
        }
        return false;
    }
};
