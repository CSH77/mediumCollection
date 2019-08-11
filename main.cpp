#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    int min;
    int max;

    int search(vector<int>& nums, int l, int r, int target)
    {
        if(l == r)
            return l;

        int mid = (l + r) / 2;
        if(nums[mid] == target)
        {
            if(nums[l] == target)
                min = l;

            if(nums[r] == target)
                max = r;

            search(nums, l, mid - 1);
        }




    }

    vector<int> searchRange(vector<int>& nums, int target) {

    }
};

int main()
{
    vector<int> input = {5,7,7,8,8,10};

    return 0;
}



