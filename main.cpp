#include <iostream>
#include <set>
#include <vector>
#include <map>

using namespace std;

/*
Sort Colors

Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
 */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int numArr[9999] = {0};

        for(int n : nums)
        {
            numArr[n] += 1;
        }

        vector<int> answer;
        nums.clear();
        for(int i = 0; i < 9999; i++)
        {
            for(int j = numArr[i]; j > 0; j--)
            {
                nums.push_back(i);
            }
        }
    }
};

int main()
{
    Solution obj;

    vector<int> input = {2,0,2,1,1,0};
    obj.sortColors(input);

    for(int n : input)
        cout << n << " ";
    cout << endl;


    return 0;
}



