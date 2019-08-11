#include <iostream>
#include <set>
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    int binarySearch(vector<int>& nums, int l, int r, int target)
    {
        if(l > r)
            return -1;

        int mid = (l + r) / 2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] > target)
            return binarySearch(nums, l, mid - 1, target);
        else
            return binarySearch(nums, mid + 1, r, target);

    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> answer;
        int result = binarySearch(nums, 0, nums.size() - 1, target);

        if( result == -1)
            return vector<int>{-1, -1};

        int start = result;
        while(start >= 0 && nums[start] == target)
            start--;
        answer.push_back( start + 1);

        start = result;
        while(start < nums.size() && nums[start] == target)
            start++;

        answer.push_back(start - 1);

        return answer;
    }
};

int main()
{
    vector<int> input = {5,7,7,8,8,8,10,10,10,11,11,11};
    Solution obj;
    vector<int> answer = obj.searchRange(input, 11);

    for(int n : answer)
        cout << n << " ";
    cout << endl;

    return 0;
}



