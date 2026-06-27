class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>mySet(nums.begin(), nums.end());
        int ans = 0;
        for(auto it:mySet){
            int count = 1;
            int num1 = it-1;
            int num2 = it+1;
            if(mySet.find(num1) == mySet.end()){
                while(mySet.find(num2) != mySet.end()){
                    count++;
                    num2++;
                }
            }
            ans = max(count, ans);
        }
        return ans;
    }
};
