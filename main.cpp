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
        int i = 0, j = 0;
        unordered_set<char> uset;

        while(i < s.size() && j < s.size())
        {
            auto search = uset.find(s[j]);
            if(search != uset.end()) //char is already used
            {
                //delete char from set.
                uset.erase(s[i]);

                //update index i
                i++;
            }
            else // char never used before.
            {
                //update set
                uset.insert(s[j]);
                j++;

                count = j - i;
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



