class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for (int i=0;i<nums.size();i++)
        {
            if (i>0 && nums[i-1] == nums[i])
            {
                continue;
            }
            int a = nums[i];
            int l = i+1;
            int r = nums.size() - 1;
            while (l<r)
            {
                int threeSum = a + nums[l] + nums[r];
                if (threeSum < 0)
                {
                    l++;
                }
                else if (threeSum > 0)
                {
                    r--;
                }
                else
                {
                   vector<int> tmp = {a,nums[l],nums[r]}; 
                   res.push_back(tmp);
                   l++;
                   while (nums[l] == nums[l-1])
                   {
                        l++;
                   }  
                }
            }
        }
        return res;
    }
};
