class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int l = 0;
        int ans = 0;
        int sum = 0;
        for(int r=0;r<arr.size();r++){
            sum += arr[r];

            if(r-l+1 > k){
                sum -= arr[l];
                l++;
            }
            double avg = (double)sum/k;
            if(r-l+1 == k && avg >= threshold){
                ans++;
            }
        }
        return ans;
    }
};