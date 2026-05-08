class Solution {
public:
    
    void merge(vector<int>&nums, int low, int mid, int high ){
        int left = low, right = mid+1;
        vector<int> res;
        while(left <= mid && right <= high){
            if(nums[left] <= nums[right])
                res.push_back(nums[left++]);
            else
                res.push_back(nums[right++]);
        }
            while(left <= mid)
                res.push_back(nums[left++]);

            while(right <= high)
                res.push_back(nums[right++]);

            for(int i = low; i<=high; i++){
                nums[i] = res[i - low];
            }
        
    }
    void mergeSort(vector<int>&nums, int low, int high){
        if(low>=high)
            return;
        int mid = (low+high)/2;

        mergeSort(nums, low, mid);
        mergeSort(nums, mid+1, high);
        merge(nums, low, mid, high);
    }
    vector<int> sortArray(vector<int>& nums) {
        int low, high;
        low = 0;
        high = nums.size()-1;

        mergeSort(nums, low, high);
        
        return nums;
    }
};