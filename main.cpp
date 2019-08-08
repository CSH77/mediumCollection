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
    vector<vector<int>> answer;

    void subsetHelper(vector<int>& nums, vector<int> collection, int left, int right)
    {
        if(left > right)
            return;

        for(int n : collection)
            cout << n << " ";
        cout << endl;


        for(int i = left; i < right; i++)
        {
            // vector<int> temp(collection.begin(), collection.end());
            vector<int> temp = collection;
            temp.push_back(collection[i]);
            subsetHelper(nums, temp, i + 1, right);
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        subsetHelper(nums, vector<int>(), 0, nums.size());

        return answer;
    }
};

int main()
{
    vector<int> input = {1,2,3};
    Solution obj;

    obj.subsets(input);


    return 0;
}


