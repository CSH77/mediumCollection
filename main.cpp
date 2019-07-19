#include <iostream>
#include <vector>
#include <limits>

using namespace std;

/*
Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.

Example 1:
Input: [1,2,3,4,5]
Output: true

Example 2:
Input: [5,4,3,2,1]
Output: false
 */

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
            int first_s = numeric_limits<int>::max();
            int second_s = numeric_limits<int>::max();
            for(int i = 0; i < nums.size(); i++)
            {
                if(nums[i] < first_s)
                    first_s = nums[i];
                else if(nums[i] > first_s && nums[i] < second_s)
                    second_s = nums[i];
                else if(nums[i] > second_s)
                    return true;
            }
            return false;
        }
};

int main()
{
    vector<int> input = {1,2,3,4,5};

    Solution obj;
    cout << obj.increasingTriplet(input);

    return 0;
}



