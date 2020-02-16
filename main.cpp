#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> sset;

        for(int i = 0; i < nums.size(); i++)
        {
            auto search = sset.find(nums[i]);

            if(search != sset.end()) //found duplicated number.
            {
                return true;
            }
            else
                sset.insert(nums[i]);
        }
        return false;
    }
};

int main()
{
    // vector<int> input = {1,1,1,3,3,4,3,2,4,2};
    vector<int> input = {1,2,3,4};


    Solution obj;
    cout << obj.containsDuplicate(input) << endl;

    return 0;
}



