#include <string>
using namespace std;
class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for (string s : strs)
        {
            int len = s.length();
            res += to_string(len) + '#' + s;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i<s.length())
        {
            int j = i;
            while(s[j] != '#')
            {
                j += 1;
            }
            int n = stoi(s.substr(i,j-i));
            res.push_back(s.substr(j+1,n));
            i = j+1+n;
        }
        return res;    
    }
};
