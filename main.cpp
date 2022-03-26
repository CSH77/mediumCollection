#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        sub.push_back(nums[0]);

        for(int i = 1; i < nums.size(); i++)
        {
            // int test = sub[sub.size() - 1];
            int currentValue = nums[i];
            if(currentValue > sub.back())
                sub.push_back(currentValue);
            else
            {
                int index = binarySearch(sub, currentValue);
                sub[index] = currentValue;
            }
        }
        return sub.size();
    }

    int binarySearch(vector<int>& sub, int target)
    {
        int left = 0;
        int right = sub.size() - 1;
        while(left < right)
        {
            int mid = (left + right) / 2;
            if(sub[mid] == target)
                return mid;
            else if(sub[mid] < target) //go right
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};


int main()
{
    Solution obj;
    vector<int> input = {10,9,2,5,3,7,101,18}; //expect 4

    cout << obj.lengthOfLIS(input);

    return 0;
}



