#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        set<char> myset;
        int stringSize = s.length();
        int ans = 0, i = 0, j = 0;

        while(i < stringSize && j < stringSize)
        {
            auto search = myset.find(s.at(j));
            if(search == myset.end()) //The char not used,
            {
                //add new char to database
                myset.insert(s.at(j));

                //update index
                j++;

                //refresh answer.
                ans = max(ans, j - i);
            }
            else //new char used already.
            {
                //remove first char from the database.
                myset.erase(s.at(i));

                //update index
                i++;

            }
        }
        return ans;
    }

};
int main()
{
    string input = "pwwkew"; //expect The answer is "wke", with the length of 3.
    // string input = "abcabcbb";//  The answer is "abc", with the length of 3.
    // string input = "dvdf"; //expect 3
    Solution obj;
    cout << obj.lengthOfLongestSubstring(input);

    return 0;
}



