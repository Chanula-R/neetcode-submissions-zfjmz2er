class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int nonZ_product = 1;
        int Z_count = 0;
        for (int& num : nums)
        {
            product *= num;
            if (num != 0)
            {
                nonZ_product *= num;
            }
            if (num == 0)
            {
                Z_count += 1;
            }
        }

        if (Z_count > 1)
        {
            vector<int> z_res(nums.size());
            return z_res; 
        }

        vector<int> res;
        for (int& num : nums)
        {
            if (num != 0)
            {
                res.push_back(product/num);
            }
            else
            {
                res.push_back(nonZ_product);
            }

            
        }

        return res; 
    }
};
