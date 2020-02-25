#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <limits>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p1 = 0;

        int maxSellOff = 0;
        int cheapestValue = numeric_limits<int>::max();
        while(p1 < prices.size())
        {
            if(prices[p1] < cheapestValue)
            {
                cheapestValue = prices[p1];
                for(int i = p1; i < prices.size() ; i++)
                {
                    if(maxSellOff < prices[i] -prices[p1])
                        maxSellOff = prices[i] -prices[p1];
                }
            }
            p1++;
        }

        return maxSellOff;
    }
};

int main()
{
    Solution obj;
    vector<int> input = {7,1,5,3,6,4};
    // vector<int> input = {7,6,4,3,1};
    // vector<int> input = {1,2};

    cout << obj.maxProfit(input) << endl;

    return 0;
}



