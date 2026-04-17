class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0; int r = nums.size()-1;

        while (l <= r)
        {
            int mid = (l+r)/2;
            if (nums[l] <= nums[mid])
            {
                int l_min = nums[l];
                if (l_min > target)
                {
                    l = mid+1;
                }
                else if (l_min <= target)
                {
                    //r = mid-1;
                    //mid = (l+r)/2;
                    if (nums[mid] < target)
                    {
                        l = mid+1;
                    }
                    else if (nums[mid] > target)
                    {
                        r = mid-1;
                    }
                    else
                    {
                        return mid;
                    }
                }
            }
            else
            {
                int r_max = nums[r];
                if (r_max < target)
                {
                    r = mid-1;
                }
                else if (r_max >= target)
                {
                    //l = mid+1;
                    //mid = (l+r)/2;
                    if (nums[mid] < target)
                    {
                        l = mid+1;
                    }
                    else if (nums[mid] > target)
                    {
                        r = mid-1;
                    }
                    else
                    {
                        return mid;
                    }
                }
            }
        }
        return -1;    
    }
};
