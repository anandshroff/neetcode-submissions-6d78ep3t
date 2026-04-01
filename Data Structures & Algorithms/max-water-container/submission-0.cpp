class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int h=height.size()-1;
        int area = 0;
        int result=0;

        while(l<=h)
        {
            area = (h-l) * min(height[l], height[h]);
            result = max(area, result);

            if(height[l]<=height[h])
            {
                l++;
            }
            else    
                h--;
        }
        return result;

    }
};
