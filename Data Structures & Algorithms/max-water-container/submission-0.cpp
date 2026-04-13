class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxA = 0;
        int l = 0;
        int r = heights.size() -1;
        while (l < r)
        {   
            int minHeight = min(heights[l],heights[r]);
            int area = ((r-l)*minHeight);
            if (maxA < area)
            {
                maxA = area;
            }
            if (minHeight == heights[l])
            {
                l++;
            }
            else
            {
                r--;
            }

        }
        return maxA;    
    }
};
