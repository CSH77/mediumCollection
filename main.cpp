#include <iostream>
#include <set>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int maxCount = 0;
        int count = 0;
        int p1 = 0;
        int p2 = 0;
        unordered_set<char> uset;

        while(p1 < s.size() && p2 < s.size())
        {
            //char is already used
            if(uset.count(s[p2]) != 0)
            {
                //remove char from uset
                uset.erase(s[p1]);
                p1++;
            }
            else //char is never been used
            {
                uset.insert(s[p2]);
                p2++;

                //update counter
                count = p2 - p1;
                maxCount = max(count, maxCount);
            }
        }

        return maxCount;
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



