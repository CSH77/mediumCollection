#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/*
Kth Largest Element in an Array

Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5

Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4

Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
 */

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int> pque(nums.begin(), nums.end());

        for(int i = 1; i < k; i++)
            pque.pop();

        return pque.top();
    }
};

int main()
{
    // vector<int> input = {3,2,3,1,2,4,5,5,6}; //with k = 4, expect 4
    vector<int> input = {3,2,1,5,6,4}; //with k = 2, expect 5
    // vector<int> input = {3,2,3,1,2,4,5,5,6}; //with k = 4, expect 4

    Solution obj;
    cout << obj.findKthLargest(input, 2);


    return 0;
}



