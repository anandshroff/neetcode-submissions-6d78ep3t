class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0;
        int count2 = 0;
        int val1 = -1;
        int val2 = -1;
        int n = nums.size();
        for(auto num : nums){
            if(num == val1){
                count1++;
            }
            else if(num == val2){
                count2++;
            }
            else if(count1 == 0){
                    val1 = num;
                    count1 = 1;
                }
            else if(count2 == 0){
                    val2 = num;
                    count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }
        vector<int>res;
        count1 = 0;
        count2 = 0;
        for(auto it: nums){
            if(val1 == it) count1++;
            if(val2 == it) count2++;
        }
        if( count1 > n/3)
            res.push_back(val1);
        if(count2 > n/3)
            res.push_back(val2);
        
        return res;
    }
};