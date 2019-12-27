#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if( s.empty() || s.length() < 1 )
            return "";
        else if(s.length() == 1)
            return s;

        int start = 0, end = 0;
        for(unsigned int i = 0; i < s.length(); i++)
        {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = max(len1, len2);
            if (len > end - start)
            {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }

    int expandAroundCenter(string s, int left, int right) {
        int L = left, R = right;

        while (L >= 0 && R < s.length() && s.at(L) == s.at(R))
        {
            L--;
            R++;
        }
        return R - L - 1;
    }
};

int main()
{
    Solution obj;
    string input = "babad";
    cout << obj.longestPalindrome(input);

    return 0;
}



