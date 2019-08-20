#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {

        long long carry; //64 bit
        while( b != 0 )
        {
            carry = a & b;
            a = a ^ b;
            b = (carry & 0xffffffff) << 1;

        }
        return a;
    }
};

int main()
{
    Solution obj;
    cout << obj.getSum(7,5);

    return 0;
}



