class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;      // stores indices
    vector<int> ans;

    for(int i = 0; i < nums.size(); i++)
    {
        // Remove indices that are outside the current window
        while(!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }

        // Remove all smaller elements from the back
        // because they can never become maximum
        while(!dq.empty() && nums[dq.back()] < nums[i])
        {
            dq.pop_back();
        }

        // Add current index
        dq.push_back(i);

        // First window is formed when i >= k-1
        if(i >= k - 1)
        {
            // Front of deque always contains max element
            ans.push_back(nums[dq.front()]);
        }
    }

    return ans;
        
    }
};
