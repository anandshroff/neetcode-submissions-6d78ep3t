class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        
        int l = 0;
        int r = p.size()-1;
        int count = 0;
        sort(p.begin(), p.end());

       while(l<r){
        int sum = p[l] + p[r];
        if(sum>limit){
            r--;
            count++;
        }
        else{
            r--;
            l++;
            count++;
        }
       }
       if(l==r){
        count++;
       }
       return count;
    }
};