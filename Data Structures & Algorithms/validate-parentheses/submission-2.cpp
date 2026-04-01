//#include <string>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        vector<char> myStack;
        myStack.push_back(s[0]);
        for (char bracket: s.substr(1))
        {
            char LastItem = myStack.back();
            if (LastItem == '(' && bracket == ')')
            {
                myStack.pop_back();
            }
            else if (LastItem == '{' && bracket == '}')
            {
                myStack.pop_back();
            }
            else if (LastItem == '[' && bracket == ']')
            {
                myStack.pop_back();
            }
            else
            {
                myStack.push_back(bracket);
            }
        }
        if (myStack.empty())
        {
            return true;
        } 
        else
        {
            return false;
        }   
    }
};
