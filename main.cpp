#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        set<char> myset;
        int n = s.length();
        int ans = 0, i = 0, j = 0;

        while(i < n && j < n)
        {
            auto search = myset.find(s.at(j));
            if(search == myset.end())
            {
                myset.insert(s.at(j++));
                ans = max(ans, j - i);
            }
            else
            {
                myset.erase(s.at(i++));
            }
        }

        return ans;
    }

};
int main()
{
    //string input = "pwwkew"; //expect The answer is "wke", with the length of 3.
    //string input = "abcabcbb";//  The answer is "abc", with the length of 3.
    string input = "dvdf"; //expect 3
    Solution obj;
    cout << obj.lengthOfLongestSubstring(input);

    return 0;
}



