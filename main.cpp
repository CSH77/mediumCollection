#include <iostream>
#include <set>
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

        if(nums.size() < 2)
            return false;

        int low = nums[0];
        int mid = numeric_limits<int>::max();

        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] > mid) //found number that is bigger than mid, triplet found
                return true;

            if(nums[i] < low ) //update low
                low = nums[i];

            if(nums[i] > low && nums[i] < mid) //update mid
                mid = nums[i];
        }

        return false;
    }
};

int main()
{
    // vector<int> input = {1,2,3,4,5}; //true
    vector<int> input = {5,4,3,2,1}; //false
    // vector<int> input = {5,1,5,5,2,5,4}; //expect true

    Solution obj;
    cout << obj.increasingTriplet(input) << endl;

    return 0;
}



