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
        int right = nums.size() - 1;

        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] >= target) //go left
                right = mid;
            else
                left = mid + 1;
        }

        if(nums[left] != target)
            return -1;
        else
            return left;
    }

    int findHigh(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        while(left + 1 < right) //need to pay attention here for left + 1
        {
            // int mid = (left + right) / 2;
            int mid = left + (right - left) / 2;
            if(nums[mid] <= target) //still need to go right from current point
                left = mid;
            else //current is bigger than target, go left
                right = mid - 1;
        }

        //pay attention here too, why use two return case,
        if(nums[right] == target)
            return right;

        if(nums[left] == target)
            return left;

        return -1;

    }


    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() < 1)
            return vector<int>{-1, -1};

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
    vector<int> answer = obj.searchRange(input, 2);

    for(int n : answer)
        cout << n << " ";
    cout << endl;

    return 0;
}



