#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Given an array nums of n integers, are there elements a, b, c in nums
//such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
/*
Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //vector<int> temp;
        vector<vector<int>> collect;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++)
        {
            for(int j = i + 1; j < nums.size() - 1; j++)
            {
                for(int k = j + 1; k < nums.size(); k++)
                {
                    if(nums[i] + nums[j] + nums[k] == 0)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        // sort(temp.begin(), temp.end());
                        collect.push_back(temp);
                    }
                }
            }
        }

        return collect;
    }
};

int main()
{
    vector<int> input = {-1, 0, 1, 2, -1, -4};

    Solution obj;
    vector<vector<int>> vec = obj.threeSum(input);

    for(vector<int> v : vec)
    {
        for(int n : v)
        {
            cout << n << " ";
        }
        cout << endl;
    }

    return 0;
}
