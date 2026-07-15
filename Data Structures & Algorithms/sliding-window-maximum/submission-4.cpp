class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       deque<int>d;
        int l = 0;
        vector<int>ans;
        for(int r=0; r<nums.size(); r++){
            while(!d.empty() && nums[d.back()] < nums[r])
                d.pop_back();
            
            d.push_back(r);

            if(r-l+1 > k) l++;

            while(!d.empty() && d.front() < l)
                d.pop_front();
            
            if(r-l+1 == k)
                ans.push_back(nums[d.front()]);
        }
        return ans;
        
    }
};
