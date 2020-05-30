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
    int subarraySum(vector<int>& nums, int k)
    {
        int n=nums.size();
        int ans=0;
        int cur_sum=0;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)
        {
            cur_sum += nums[i];
            if(cur_sum == k)
                ans++;

            if(m.find(cur_sum - k) != m.end())
                ans += m[cur_sum - k];

            m[cur_sum]++;
        }
        return ans;
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



