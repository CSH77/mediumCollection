#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";

        if(strs.size() < 2)
            return strs[0];

        int numberOfString = strs.size();

        //sort by length of string.
        auto comp = [](string& a, string& b){
            return a.size() < b.size();
        };
        sort(strs.begin(), strs.end(), comp);

        string answer;

        int stringIndex = 0;
        for(int i = 0; i < strs[0].length(); i++)
        {
            char charToCompare = strs[0][i];
            bool commonChar = true;
            for(int j = 0; j < strs.size(); j++)
            {
                if(charToCompare != strs[j][i])
                {
                    commonChar = false;
                    break;
                }
            }
            if(commonChar)
                answer.push_back(charToCompare);
            else
                break;
        }
        return answer;
    }
};

int main()
{
    // vector<string> input = {"flower","flow","flight"};
    // vector<string> input = {"a"};
    // vector<string> input;
    vector<string> input = {"aca","cba"};


    // vector<string> input = {"dog","racecar","car"};
    Solution obj;
    string answer = obj.longestCommonPrefix(input);

    cout << answer << endl;

    return 0;
}



