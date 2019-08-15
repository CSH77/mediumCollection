#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {

        int goalIndex = nums.size() - 1;
        int currentIndex = goalIndex;

        for(int i = nums.size() - 1; i >= 0; i--)
        {
            currentIndex = i;
            if( (nums[currentIndex] + currentIndex ) >= goalIndex )
            {
                goalIndex = currentIndex;
            }
        }

        if(goalIndex == 0)
            return true;
        else
            return false;
    }
};


int main()
{
    // vector<int> input = {2,3,1,1,4}; //true
    vector<int> input = {3,2,1,0,4}; //true

    Solution obj;

    cout << obj.canJump(input);

    return 0;

}



