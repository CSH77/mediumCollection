#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>
#include <map>

using namespace std;

class Solution {
public:

    vector<string> answer;
    map<string, string> mmap =
    {
        {"2", "abc"},
        {"3", "def"},
        {"4", "ghi"},
        {"5", "jkl"},
        {"6", "mno"},
        {"7", "pqrs"},
        {"8", "tuv"},
        {"9", "wxyz"}
    };

    void getCombination(string comb, string digits)
    {
        if(digits.size() == 0)
        {
            // answer.insert(answer.end(), comb);
            answer.push_back(comb);
        }
        else
        {
            for(int i = 0; i < mmap[ digits.substr(0, 1) ].size(); i++ )
            {
                string temp = comb + mmap[digits.substr(0,1)][i];
                string d = digits.substr(1);
                getCombination(temp, d);
            }
        }
    }//getCombination


    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return answer;

        getCombination("", digits);
        return answer;
    }//EOF letterCombinations
};

int main()
{
    string input = "23";
    // string input = "2";

    Solution obj;
    vector<string> answer = obj.letterCombinations(input);

    for(string s : answer)
        cout << s << " ";
    cout << endl;

    return 0;
}




