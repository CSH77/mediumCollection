#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    struct Element
    {
        char paren;
        int position;
        Element(char p, int pos) : paren(p), position(pos){};
    };

    string minRemoveToMakeValid(string s) {
        stack<Element> rec;

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
                rec.push(Element{'(', i});
            else if(s[i] == ')') //find matching parenthesis
            {
                if(rec.empty()) //no matching parenthesis, this position need to be deleted.
                    s[i] = '*'; //makr with * to delete this position later
                else
                    rec.pop();
            }
        }

        //left over item in rec need to be deleted,
        while(!rec.empty())
        {
            Element temp = rec.top();
            rec.pop();
            s[temp.position] = '*';
        }

        string answer;

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] != '*')
                answer = answer + s[i];
        }

        return answer;

    }
};

int main()
{
    Solution obj;

    // string input = "lee(t(c)o)de)";
    // string input = "a)b(c)d";
    string input = "(a(b(c)d)";


    string answer = obj.minRemoveToMakeValid(input);
    cout << answer << endl;

    return 0;
}



