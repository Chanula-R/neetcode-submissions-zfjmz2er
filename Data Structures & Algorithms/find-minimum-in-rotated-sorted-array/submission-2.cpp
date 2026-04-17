class Solution {
public:
    int findMin(vector<int> &nums) {
        int res = nums[0];
        int l = 0; int r = nums.size()-1;

        while ( l <= r)
        {
            if (nums[l] < nums[r])
            {
               return min(res,nums[l]); 
            }

            int mid = (l+r)/2;
            res = min(res,nums[mid]);
            if (nums[mid] >= nums[l])
            {
                //mid is in left sorted array
                l = mid + 1;   //search right sorted array
            }
            else 
            {
                r = mid - 1; // we are in the right sorted array. answer is in the left most cornor
            }
        }
        return res;
    }
};
