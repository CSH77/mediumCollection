#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        //get mid,
        int mid = s.size() / 2;

        for(int i = s.size() - 1; i >= mid; i--)
        {
            swap(s[i], s[s.size() - 1 - i]);
        }
    }
};

int main()
{
    vector<char> input = {'h','e','l','l','o'};
    Solution obj;
    obj.reverseString(input);

    for(auto c : input)
        cout << c << " ";
    cout << endl;

    return 0;
}

