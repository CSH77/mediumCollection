#include <iostream>
#include <set>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {

        int l = 1, r = x;
        while(l <= r)
        {
            long long int mid = l + (r - l) / 2;
            if(mid * mid == x)
                return mid;
            else if(mid * mid < x)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l - 1;
    }
};

int main()
{
    Solution obj;
    cout << obj.mySqrt(8); //expect 2;

    return 0;
}



