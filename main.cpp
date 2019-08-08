#include <iostream>
#include <vector>
#include <set>
using namespace std;

/*
Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
 */

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> vv;
        vector<int> v;

        if (nums.size() == 0)
            return vv;

        PowerSet(vv, v, nums, 0);

        return vv;
    }

    void PowerSet(vector<vector<int>>& vv, vector<int>& v,vector<int>& nums, int begin) {

        vv.push_back(v);

        for(int i = begin; i < nums.size(); i++)
        {
            v.push_back(nums[i]);
            PowerSet(vv, v, nums, i+1);
            v.pop_back();
        }
    }
};

int main()
{
    vector<int> input = {1,2,3};
    Solution obj;

    vector<vector<int>> answer = obj.subsets(input);

    for(vector<int> v : answer)
    {
        for(int n : v)
            cout <<  n << " ";
        cout << endl;
    }


    return 0;
}


