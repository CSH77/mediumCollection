#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS( vector<int>& nums ) {
        if(nums.size() < 1)
            return 0;

        vector<int> vec(nums.size(), 1);

        int longest = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[i] > nums[j])
                {
                    if(vec[i] < vec[j] + 1)
                        vec[i] = vec[j] + 1;

                    longest = max(vec[i], longest);
                }
            }
        }
        return longest;
    }
};

int main()
{
    // vector<int> input = {10,9,2,5,3,7,101,18}; //expect 4   {2,3,7,101}
    vector<int> input = {3,4,-1, 0, 6, 2, 3}; //expect  4   {-1, 0, 2, 3}

    Solution obj;
    cout << obj.lengthOfLIS(input);


    return 0;
}



