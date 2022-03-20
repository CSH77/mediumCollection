#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {

public:

    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return -1;

        int start = 0;
        int end = nums.size() - 1;
        // int mid = (start + end) / 2;

        while(start < end)
        {
            int mid = (start + end) / 2;
            if(nums[mid] == target)
                return mid;

            if(nums[start] <= nums[mid]) // properly sorted, this part is not rotated.
            {
                if(nums[mid] > target && nums[start] <= target) //target is in range, go left
                    end = mid - 1;
                else  //not in range. go right
                    start = mid + 1;
            }
            else //it is rotated at some point
            {
                if(nums[mid] < target && nums[end] >= target)  //in range go right
                    start = mid + 1;
                else //go left
                    end = mid - 1;
            }
            mid = (start + end) / 2;
        }//while

        if(nums[start] == target )
            return start;

        return -1;
    }
};

int main()
{
    // vector<int> input = {1,3};
    vector<int> input = {4,5,6,7,0,1,2};
    Solution obj;
    cout << obj.search(input, 1);

    return 0;
}



