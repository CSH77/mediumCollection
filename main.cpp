#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // set<char> sset;
        int count = 0;
        int maxCount = 0;

        for(int i = 0; i < s.size(); i++)
        {
            set<char> sset;
            int curIndex = i;
            count = 0;
            while( curIndex < s.size())
            {
                auto search = sset.find(s[curIndex]);
                if(search != sset.end()) // repeated char
                {
                    break;
                }
                else
                {
                    sset.insert(s[curIndex]);
                    count++;
                }

                if(count > maxCount)
                    maxCount = count;

                curIndex++;
            }
        }
        return maxCount;
    }
};

int main()
{
    //string input = "pwwkew"; //expect The answer is "wke", with the length of 3.
    string input = "abcabcbb";//  The answer is "abc", with the length of 3.
    // string input = "dvdf"; //expect 3
    Solution obj;
    cout << obj.lengthOfLongestSubstring(input);

    return 0;
}



