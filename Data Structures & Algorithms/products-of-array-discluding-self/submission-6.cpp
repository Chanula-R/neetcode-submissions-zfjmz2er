class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,1);
        int pre_fix = 1;
        for (int i = 1; i< n; i++)
        {
            pre_fix *= nums[i-1];
            res[i] = pre_fix;
        }

        int post_fix = 1;
        for (int i = n-2; i>=0 ; i--)
        {
            post_fix *= nums[i+1];
            res[i] *= post_fix ;
        }

        return res;
    }
};
