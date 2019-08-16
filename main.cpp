#include <iostream>
#include <set>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while(1)
        {
            long long sum = 0;
            while(n)
            {
                int digit = n % 10;
                sum = sum + digit * digit;
                n = n / 10;
            }
            if(sum == 1)
                return true;
            else if(s.find(sum) != s.end())
            {
                return false;
            }
            else
            {
                s.insert(sum);
                n = sum;
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



