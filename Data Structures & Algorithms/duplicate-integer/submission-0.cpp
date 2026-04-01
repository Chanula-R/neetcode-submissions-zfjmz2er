using namespace std;
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> mySet;
        int array_size = nums.size();
        while (!nums.empty())
        {
            int Last_element = nums.back();
            nums.pop_back();
            mySet.insert(Last_element);
        }
        int set_size = mySet.size();
        if (array_size == set_size)
        {
            return false;
        }
        else
        {
            return true;
        }   
    }
};