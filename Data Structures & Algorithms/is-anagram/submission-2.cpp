#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> map_s;
        unordered_map<char,int> map_t;
        if (s.length()!= t.length())
        {
            return false;
        }
        for(int i=0;i<s.length();i++)
        {
            map_s[s[i]] += 1;
            map_t[t[i]] += 1;
        }
        if (map_s == map_t)
        {
            return true;
        }
        else
        {
            return false;
        }

    }
};
