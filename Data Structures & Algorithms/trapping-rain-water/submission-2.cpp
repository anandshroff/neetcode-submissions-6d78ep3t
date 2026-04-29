class Solution {
public:
    int trap(vector<int>& height) {
        int left = 1;
        int right = height.size()-2;
        int Lmax = height[left-1];
        int Rmax = height[right+1];
        int res = 0;
        while(left <= right)
        {
            if(Rmax <= Lmax){
                res += max(0, Rmax - height[right]);
                Rmax = max(Rmax, height[right]);
                right--;
            }
            else{
                res += max(0, Lmax - height[left]);
                Lmax = max(Lmax, height[left]);
                left++;
            }
        }
        
        return res;
    }
};
