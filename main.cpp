#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
#include <string>
using namespace std;

/*
Given a sorted integer array nums, where the range of elements are in the inclusive range [lower, upper], return its missing ranges.

Example:

Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
Output: ["2", "4->49", "51->74", "76->99"]
 */

class Solution {
public:
vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        long left, right;
        left = lower, right = lower;

        for(int i = 0; i < nums.size(); i++)
        {
            right = (long)nums[i] - 1;
            if(right >= left)
            {
                if(right == left)
                    ans.push_back(to_string(left));
                else
                    ans.push_back(to_string(left) + "->" + to_string(right) );
            }
            left = (long)nums[i] + 1;
        }

        if(left <= upper)
        {
            if( left == upper)
                ans.push_back(to_string(left));
            else
                ans.push_back(to_string(left) + "->" + to_string(upper));
        }

        return ans;
    }
};

int main()
{
    vector<int> input = {0, 1, 3, 50, 75}; // expect ["2", "4->49", "51->74", "76->99"]

    Solution obj;
    vector<string> vec = obj.findMissingRanges(input, 0, 99);

    for(string s : vec)
    {
        cout << s << ", ";
    }
    cout << endl;

    return 0;
}



