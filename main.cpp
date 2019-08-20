#include <iostream>
#include <set>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> stk;
        for(int i = 0; i < tokens.size(); i++)
        {
            int a, b;

            if(tokens[i] == "+")
            {
                b = stk.top();
                stk.pop();
                a = stk.top();
                stk.pop();

                stk.push(a + b);
            }
            else if(tokens[i] == "*")
            {
                b = stk.top();
                stk.pop();
                a = stk.top();
                stk.pop();

                stk.push(a * b);
            }
            else if(tokens[i] == "-")
            {
                b = stk.top();
                stk.pop();
                a = stk.top();
                stk.pop();

                stk.push(a - b);
            }
            else if(tokens[i] == "/")
            {
                b = stk.top();
                stk.pop();
                a = stk.top();
                stk.pop();

                stk.push(a / b);
            }
            else //not operator, push number to stack.
            {
                stk.push(stoi(tokens[i]));
            }
        }

        int answer = stk.top();
        return answer;

    }
};

int main()
{
    // vector<string> input = {"2", "1", "+", "3", "*"}; //expect 9
    vector<string> input = {"4", "13", "5", "/", "+"}; //expect 6

    // vector<string> input = {"2", "1", "+"};
    Solution obj;
    cout << obj.evalRPN(input);


    return 0;
}
