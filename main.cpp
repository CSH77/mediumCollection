#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 1)
            return 0;

        int ptr1 = 0;
        int ptr2 = 0;

        while(ptr2 < nums.size())
        {
            if(nums[ptr1] != nums[ptr2])
            {
                ptr1++;
                nums[ptr1] = nums[ptr2];
            }
            ptr2++;
        }

        return ptr1 + 1;

    } //Solution
};

int main()
{
    vector<int> vec = {0,0,1,1,1,2,2,3,3,4};
    // vector<int> vec = {1,1,2};
    for(auto v : vec)
        cout << v << " ";
    cout << endl;

    Solution obj;
    cout << "index: " << obj.removeDuplicates(vec) << endl;


    for(auto v : vec)
        cout << v << " ";
    cout << endl;

    return 0;
}



