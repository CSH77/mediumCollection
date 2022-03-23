#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() < 2)
            return true;

        int goalIndex = nums.size() - 1;
        int currentIndex = 0;
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            int maxJump = nums[i];
            currentIndex = i;
            if( (maxJump + currentIndex) >= goalIndex  )
                goalIndex = currentIndex;
        }
        if(goalIndex == 0)
            return true;
        else
            return false;
    }
};


int main()
{
    vector<int> input = {2,3,1,1,4}; //true
    //vector<int> input = {3,2,1,0,4}; //false

    Solution obj;

    cout << obj.canJump(input);

    return 0;

}



