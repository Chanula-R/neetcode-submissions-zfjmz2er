// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
using namespace std;
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) 
    {
        if (pairs.empty())
        {
            return {};
        }
        vector<vector<Pair>> res;
        res.push_back(pairs);
        int length = pairs.size();

        for (int i =1 ;i<length ;i++)
        {
            int key = pairs[i].key;
            string value = pairs[i].value;
            int j = i-1;
            while(j>=0 && pairs[j].key > key)
            {
                pairs[j+1].key = pairs[j].key;
                pairs[j+1].value = pairs[j].value;
                j--;
            }
            pairs[j+1].key = key;
            pairs[j+1].value = value;
            res.push_back(pairs); 
        }
    return res;
    }
};
