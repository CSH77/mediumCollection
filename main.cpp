#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    void backTrack(vector<string>& answer, string cur, int open, int close, int max)
    {
        if(close > open || open > max || close > max)
            return;

        if(open == close && close == max)
            answer.push_back(cur);

        backTrack(answer, cur + "(", open + 1, close, max);
        backTrack(answer, cur + ")", open, close+ 1, max);
    }


    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backTrack(ans, "", 0, 0, n);

        return ans;

    }
};



int main()
{
    Solution obj;
    vector<string> ans = obj.generateParenthesis(3);

    for(string s : ans)
        cout << s << " ";

    return 0;
}



