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
    bool increasingTriplet(vector<int>& nums) {
        int first = numeric_limits<int>::max();
        int second = numeric_limits<int>::max();
        int third = numeric_limits<int>::max();

        for (int i = 0; i < nums.size(); i++)
        {
            int currentValue = nums[i];
            if(currentValue <= first) //smallest number.
            {
                first = currentValue;
            }
            else if(currentValue <= second)
            {
                second = currentValue;
            }
            else // current is bigger than both first and second, found triplet.
            {
                cout << first << " " << second << " " << currentValue << endl;
                return true;
            }
        }
        return false;
    }
};

int main()
{
    vector<int> nums = {2,1,5,0,4,6};
    // vector<int> nums = {5,4,3,2,1};
    // vector<int> nums = {20,100,10,12,5,13};


    Solution obj;
    cout << obj.increasingTriplet(nums);


    return 0;
}



