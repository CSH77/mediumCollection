#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int zeroCount = 0;
        for(int i = 5; i < n + 1; i += 5)
        {
            int current = i;
            while(current % 5 == 0)
            {
                zeroCount++;
                current = current / 5;
            }
        }
        return zeroCount;
    }
};

int main()
{
    Solution obj;
    //cout << obj.trailingZeroes(5); //120 => 1 trailing zero.
     //cout << obj.trailingZeroes(4);
    //cout << obj.trailingZeroes(3); //3! = 6, no trailing zero.
    cout << obj.trailingZeroes(30); //expect 7;

    return 0;
}



