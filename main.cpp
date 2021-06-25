#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        set<char> myset;
        string currentStr = "";
        int maxLength = 0;
        for(int i = 0; i < s.length(); i++)
        {
            auto search = myset.find(s.at(i));
            if(search != myset.end())
            {
                size_t pos = currentStr.find( s.at(i) );
                currentStr = currentStr.substr(pos + 1);
                currentStr = currentStr + s.at(i);
            }
            else
            {
                currentStr = currentStr + s.at(i);
                myset.insert(s.at(i));
            }

            maxLength = max(maxLength, int(currentStr.length()) );
        }  

        

        return maxLength;
    }

};
int main()
{
    // string input = "pwwkew"; //expect The answer is "wke", with the length of 3.
    // string input = "abcabcbb";//  The answer is "abc", with the length of 3.
    string input = "dvdf"; //expect 3
    Solution obj;
    cout << obj.lengthOfLongestSubstring(input);

    return 0;
}



