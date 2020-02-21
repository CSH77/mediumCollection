#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;

        int arr[255];
        for(int i = 0; i < 255; i++)
            arr[i] = 0;

        for(int i = 0; i < s.size(); i++)
            arr[s[i]] += 1;

        for(int i = 0; i < s.size(); i++)
        {
            arr[t[i]] -= 1;
            if(arr[t[i]] < 0)
                return false;
        }

        return true;
    }
};

int main()
{
    // string s = "anagram", t = "nagaram";
    string s = "rat", t = "car";

    Solution obj;
    cout << obj.isAnagram(s, t) << endl;

    return 0;
}



