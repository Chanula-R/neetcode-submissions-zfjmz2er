#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map1;
        unordered_map<int,vector<int>> map2;
        vector<int> res;

        for (int num : nums)
        {
            map1[num] += 1;
        }

        for (const auto& pairs : map1)
        {
            map2[pairs.second].push_back(pairs.first);
        }

        int i = nums.size();
        while (i>0)
        {
            if (map2.contains(i))
            {
                for (int n : map2[i])
                {
                    res.push_back(n);
                }
            }
            if(res.size() == k)
            {
                return res;
            }
            i--;
        }
    }
};
