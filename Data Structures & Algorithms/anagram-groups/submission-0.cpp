#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> res;
        for (string word : strs)
        {
            vector<int> count(26,0);
            for (char letter : word)
            {
                count[letter-'a'] += 1;
            }
            string count_s = to_string(count[0]);
            for (int i =1 ; i<26;i++)
            {
                count_s += ',' + to_string(count[i]); 
            }

            res[count_s].push_back(word);

        }
        vector<vector<string>> result;
        for (const auto& pair : res)
        {
            result.push_back(pair.second);
        }

        return result; 
    }
};
