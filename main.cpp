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
    int maxSubArray(vector<int>& nums) {
        int maxSum = numeric_limits<int>::min();
        int currentSum = numeric_limits<int>::min();

        for(int i = 0; i < nums.size(); i++)
        {
            currentSum = max(currentSum, 0) + nums[i];
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};

int main()
{
    Solution obj;
    vector<int> input = {-2,1,-3,4,-1,2,1,-5,4};
    cout << obj.maxSubArray(input) << endl;

    return 0;
}


