#include <iostream>
#include <set>
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    int findLow(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size();

        while(left < right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] >= target) //go left
                right = mid;
            else
                left = mid + 1;

            if(left == right && nums[left] == target)
                return left;
        }

        return -1;
    }

    int findHigh(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size();
        bool found = false;

        while(left < right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] <= target) //go right
            {
                left = mid + 1;

                if(nums[mid] == target)
                    found = true;
            }
            else //go left
                right = mid;

            if(left == right && found)
                return left - 1;

        }
        return -1;
    }


    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> answer;
        int left = findLow(nums, target);
        int right = findHigh(nums, target);
        answer.push_back(left);
        answer.push_back(right);

        return answer;
    }
};

int main()
{
    // vector<int> input = {5,7,7,8,8,8,10,10,10,11,11,11};
    vector<int> input = {2,2};
    Solution obj;
    vector<int> answer = obj.searchRange(input, 3);

    for(int n : answer)
        cout << n << " ";
    cout << endl;

    return 0;
}



