#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {

        int total = 0;
        size_t next = 1;
        for(int i = s.size() - 1; i >= 0; i--)
        {
            int cur = (s[i] - 'A') + 1;
            total += cur * next;
            next = next * ('Z' - 'A' + 1);
        }
        return total;
    }
};


int main()
{
    Solution obj;
    cout << obj.titleToNumber("A");

    return 0;
}



