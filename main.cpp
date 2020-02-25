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
        int maxProfit = 0;
        int min = numeric_limits<int>::max();

        for(int i = 0; i < prices.size(); i++)
        {
            if(prices[i] < min)
                min = prices[i];
            else //time to sell!
            {
                if(prices[i] - min > maxProfit)
                    maxProfit = prices[i] - min;
            }
        }
        return maxProfit;
    }
};

int main()
{
    Solution obj;
    // vector<int> input = {7,1,5,3,6,4};
    // vector<int> input = {7,6,4,3,1};
    vector<int> input = {1,2};

    cout << obj.maxProfit(input) << endl;

    return 0;
}



