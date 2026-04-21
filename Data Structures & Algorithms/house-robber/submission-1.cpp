class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1 = 0;
        int rob2 = 0;

        for (int num : nums)
        {
            int tmp = rob1;
            rob1 = rob2;
            rob2 = max(rob2,tmp+num);
        }
        return rob2;
    }
};
