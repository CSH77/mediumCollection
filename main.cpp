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
    int findLengthOfLCIS(vector<int>& nums) {

        if(nums.size() < 1)
            return 0;

        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = 1;

        int longest = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] > nums[i - 1])
                dp[i] = dp[i - 1] + 1;
            else
                dp[i] =  1;

            longest = max(dp[i], longest);
        }
        return longest;
    }
};

int main()
{
    // vector<int> input = {1,3,5,4,7}; //expect 3
    // vector<int> input = {2,2,2,2,2}; //expect 1
    vector<int> input = {1,3,5,7}; //expect 4

    Solution obj;

    int answer = obj.findLengthOfLCIS(input);

    cout << answer << endl;

    return 0;
}




