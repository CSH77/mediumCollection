#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        // vector<int> dp = vector<int>(amount + 1, amount + 1);
        vector<int> dp = vector<int>(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++)
        {
            for (int j = 0; j < coins.size(); ++j)
            {
                if (coins[j] <= i)
                    dp[i] = std::min(dp[i], dp[i - coins[j]] + 1);
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};

int main()
{
    vector<int> input = {1, 2, 5}; //amount 11, expect 3
    // vector<int> input = {2}; //amount 3, expect -1
    // vector<int> input = {2,5,10,1}; //amount 27, expect 4
    // vector<int> input = {186,419,83,408}; //amount 6249, expect 20

    Solution obj;
    cout << obj.coinChange(input, 11);
    // cout << obj.coinChange(input, 27);
    // cout << obj.coinChange(input, 6249);// expect 20

    return 0;
}

