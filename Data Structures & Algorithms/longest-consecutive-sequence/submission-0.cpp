class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mySet;
        int max_length = 0;
        for (int num : nums)
        {
            mySet.insert(num);
        }
        for (int num : nums)
        {
            int next = num+1;
            int length = 1;
            while (mySet.count(next))
            {
                length++;
                next += 1;
            }
            if (length > max_length)
            {
                max_length = length;
            }
        }
        return max_length;
    }
};
