class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int row = arr.size();
        int col = arr[0].size();
        int top = 0, bot = row-1;
        while(top<=bot){
            int mid = top + (bot-top)/2;
            if(target>arr[mid][col-1])
                top = mid+1;
            else if(target<arr[mid][0])
                bot = mid-1;
            else
                break;
        }
        if(!(top<=bot))
            return false;

        int mid = (top+bot)/2;
        int l=0, r=col-1;
        while(l<=r){
            int m = (l+r)/2;
            if(target>arr[mid][m])
                l = m+1;
            else if(target<arr[mid][m])
                r = m-1;
            else
                return true;
        }
        return false;
    }
};
