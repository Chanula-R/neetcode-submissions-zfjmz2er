#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> twoS = {};
        unordered_map<int,int> myMap;
        for (int i = 0; i<nums.size();i++)
        {
            int new_target = target - nums[i];
            if (!myMap.empty() && myMap.contains(new_target))
            {
                twoS.push_back(myMap[new_target]);
                twoS.push_back(i);
            }
            myMap[nums[i]] = i;
        }
        return twoS;
    }
};
