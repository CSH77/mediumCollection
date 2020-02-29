#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        if(nums.size() == 0)
            return -1;

        while(left < right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] == target)
                return mid;

            if(nums[left] <= nums[mid]) //properly sorted, this part is not rotated.
            {
                if(nums[mid] > target && nums[left] <= target) //go left
                    right = mid - 1;
                else //go right
                    left = mid + 1;
            }
            else // this part is rotated somewhere.
            {
                if(nums[mid] < target && nums[right] >= target)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }//while

        if(nums[left] == target)
            return left;

        return -1;
    }
};

int main()
{
    vector<int> input = {4,5,6,7,0,1,2};

    Solution obj;
    cout << obj.search(input, 0) << endl; //expect 4;

    return 0;
}



