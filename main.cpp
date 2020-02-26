#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {

        if(s.length() % 2 != 0)
            return false;

        stack<char> stk;
        for(char c : s)
        {
            switch(c)
            {
                case '(':
                case '{':
                case '[':
                    stk.push(c);
                    break;
                case ')':
                {
                    if(stk.empty())
                        return false;
                    char comp = stk.top();
                    stk.pop();
                    if(comp != '(')
                        return false;
                    break;
                }
                case '}':
                {
                    if(stk.empty())
                        return false;
                    char comp = stk.top();
                    stk.pop();
                    if(comp != '{')
                        return false;
                    break;
                }
                case ']':
                {
                    if(stk.empty())
                        return false;
                    char comp = stk.top();
                    stk.pop();
                    if(comp != '[')
                        return false;
                    break;
                }
                default:
                    break;
            }
        }
        if(!stk.empty())
            return false;

        return true;
    }
};

int main()
{
    // string input = "()[]{}"; //true
    // string input = "([)]"; //false
    string input = "("; //false

    Solution obj;
    cout << obj.isValid(input) << endl;

    return 0;
}



