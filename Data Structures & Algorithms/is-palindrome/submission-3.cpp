#include<vector>
#include<string>
#include<cctype>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length() -1;
        while (l<r)
        {
            while ((l<r)&&(!is_alphanumeric(s[l])))
            {
                l += 1;
            }

            while ((l<r)&&(!is_alphanumeric(s[r])))
            {
                r -= 1;
            }
            if (tolower(s[l]) != tolower(s[r]))
            {
                return false;
            }
            l++;
            r--;
            
        }
        return true;
    }

    bool is_alphanumeric(char c)
    {
        return ((('A'<=c)&&(c<='Z'))
                ||(('a'<=c)&&(c<='z'))
                ||(('0'<=c)&&(c<='9')));
    }
};
