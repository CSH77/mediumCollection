#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int searchIndex;
    int bs(vector<int>& nums, int l, int r, int target)
    {
        if(r < l)
            return -1;

        int mid = (l + r) / 2;

        if(nums[mid] == target)
            return mid;

        if(nums[mid] > target) //to the left
            return bs(nums, l,  mid - 1, target);
        else
            return bs(nums, mid + 1, r, target);
    }

public:

    int search(vector<int>& nums, int target) {
        if(nums.empty())
            return -1;
        else if(nums.size() < 2)
        {
            if(nums[0] == target)
                return 0;
            else
                return -1;
        }


        int start = nums[0];
        sort(nums.begin(), nums.end());

        int startIndex = bs(nums, 0, nums.size(), start);
        int searchIndex = bs(nums, 0, nums.size(), target);
        cout << "startindex: " << startIndex << endl;
        cout << "searchIndex: " << searchIndex << endl;

        if(searchIndex == -1)
            return -1;

        if(searchIndex < startIndex)
            return searchIndex + 1 + startIndex;
        else
            return searchIndex - startIndex;
    }
};

int main()
{
    vector<int> input = {1,3};
    // vector<int> input = {4,5,6,7,0,1,2};
    Solution obj;
    cout << obj.search(input, 2);

    return 0;
}



