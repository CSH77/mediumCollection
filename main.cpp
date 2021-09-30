#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int finalStep = cost.size();
        // if(finalStep <= 3)
        //     return 0;

        vector<int> minCost;
        minCost.push_back(0);
        minCost.push_back(0);
        // minCost.resize(finalStep + 1, 0);


        for(int i = 2; i <= cost.size(); i++)
        {
            // minCost[i] = min( (minCost[i - 2] + cost[i - 2]), minCost[i - 1] + cost[i - 1] );
            int minimumCost = min( (minCost[i - 2] + cost[i - 2]), minCost[i - 1] + cost[i - 1] );
            minCost.push_back(minimumCost);
        }
        return minCost[finalStep];
    }
};


int main()
{
    // vector<int> cost = {1,100,1,1,1,100,1,1,100,1}; //Output: 6
    // vector<int> cost = {10,15,20}; //Output: 15
    vector<int> cost = {1, 100}; //Output: 1

    Solution obj;
    int answer = obj.minCostClimbingStairs(cost);

    cout << "answer: " << answer << endl;

    return 0;
}
