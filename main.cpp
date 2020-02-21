#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> vec;

        for(int i = 0; i < s.size(); i++)
        {
            if(isalpha(s[i]) || isdigit(s[i]))
                vec.push_back(tolower(s[i]));
        }

        int mid = (vec.size() / 2) - 1;

        //compare char from end
        for(int i = vec.size() - 1; i > mid; i--)
        {
            int leftIndex = vec.size() - i - 1;
            if(vec[leftIndex] != vec[i])
                return false;
        }
        return true;
    }
};

int main()
{
    //AmanaplanacanalPanama
    string input = "A man, a plan, a canal: Panama";

    // string input = "0P"; //expect false

    //raceacar
    // string input = "race a car";

    Solution obj;
    cout << obj.isPalindrome(input) << endl;


    return 0;
}



