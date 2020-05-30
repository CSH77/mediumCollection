#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.size() == 1)
        {
            if(nums[0] == k)
                return 1;
            else
                return 0;
        }
        else if(nums.size() < 1)
            return 0;

        unordered_map<int, int> umap;

        umap.insert(make_pair(0, 1));

        int sum = 0;
        int sum_minus_k = sum - k;
        int count = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            //add number to lastMap value and find that value as key.
            sum += nums[i];
            sum_minus_k += nums[i];
            auto search = umap.find(sum);
            if(search != umap.end()) //number exist, add occurance,
                search->second += 1;
            else //number does not exist, add new pair of number.
                umap.insert(make_pair(sum, 1));

            //if sum-k as key exist, increase count;
            search = umap.find(sum_minus_k);
            if(search != umap.end()) //exist
                count++;
        }

        return count;
    }
};

int main()
{
    Solution obj;
    // vector<int> input = {1,1,1};

    // vector<int> input = {3,4,7,2,-3,1,4,2};
    // cout << obj.subarraySum(input, 7); //expect 2.

    vector<int> input = {-1,-1,1};
    cout << obj.subarraySum(input, 0); //expect 1

    return 0;
}



