#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        vector<size_t> dp(n + 1, 0);
        if(n <= 2)
            return 0;

        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        for(int i = 3; i < n + 1; i++)
        {
            dp[i] = i * dp[i - 1];
        }

        //find trailing zero
        size_t total = dp[n];
        int count = 0;
        cout << "total: " << total << endl;

        while(total)
        {
            if ( total % 10 == 0 )
                count++;
            else
                return count;

            total = total / 10;
        }
        return count;
    }
};

int main()
{
    Solution obj;
    //cout << obj.trailingZeroes(5); //120 => 1 trailing zero.
    // cout << obj.trailingZeroes(4);
    //cout << obj.trailingZeroes(3); //3! = 6, no trailing zero.
    cout << obj.trailingZeroes(30); //expect 1;

    return 0;
}



