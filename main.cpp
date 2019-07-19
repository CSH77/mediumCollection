#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() <= 2) return {};

        vector<vector<int>>v;
        sort(nums.begin(), nums.end()); // sort the numbers

        for(int i = 0; i < nums.size() - 2; i++)
        {
            if(i > 0 && nums[i] == nums[i-1])
                continue; // to remove duplicates for ith candidate

            int l = i+1, r = nums.size() - 1;
            while(l < r)
            {
                if(nums[i] + nums[l] + nums[r] == 0)
                {
                    v.push_back({nums[i], nums[l], nums[r]}); // will automatically contain only unique triplets
                    l++;
                    r--;
                    while(l < r && nums[l] == nums[l-1])
                        l++; // remove duplicates and move to right

                    while(l < r && nums[r] == nums[r+1])
                        r--; // remove duplicates and move to left
                }
                else if(nums[i] + nums[l] + nums[r] > 0)
                    r--; // our sum exceeds 0, we will have to decrement 'r' so as to make the sum approach to 0
                else
                    l++; // our sum is less than 0, increment 'l' so as to make sum approach to 0
            }
        }
        return v;
    }
};

int main()
{
    vector<int> input = {-1, 0, 1, 2, -1, -4};
    // vector<int> input = {0};

    Solution obj;
    vector<vector<int>> vec = obj.threeSum(input);

    for(vector<int> v : vec)
    {
        for(int n : v)
        {
            cout << n << " ";
        }
        cout << endl;
    }

    return 0;
}
