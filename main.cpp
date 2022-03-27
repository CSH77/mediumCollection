#include <iostream>
#include <set>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> sset;
        while(1)
        {
            long long total = 0;
            while(n)
            {
                int digit = n % 10;
                total += (digit * digit);
                n = n / 10;
            }

            if(total == 1)
                return true;
            else if(sset.find(total) != sset.end())
                return false;
            else
            {
                sset.insert(total);
                n = total;
            }
        }//while
   }//EOF
};


int main()
{
    Solution obj;
    cout << obj.isHappy(19);

    return 0;
}



