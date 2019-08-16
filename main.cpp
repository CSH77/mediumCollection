#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS( vector<int>& nums ) {
        size_t size = nums.size();
        if( size == 0 )
            return 0;

        int longest = 1;
        vector<int> lisLength( size, 1 );

        for( int i = 0; i < size; i++ )
        {
            for( int j = 0; j < i; j++ )
            {
                if( nums[i] > nums[j] )
                {
                    lisLength[i] = max( lisLength[i], lisLength[j] + 1 );
                }
            }
            longest = max( longest, lisLength[i] );
        }
        return longest;
    }
};

int main()
{
    vector<int> input = {10,9,2,5,3,7,101,18}; //expect 4   {2,3,7,101}
    // vector<int> input = {3,4,-1, 0, 6, 2, 3}; //expect  4   {-1, 0, 2, 3}

    Solution obj;
    cout << obj.lengthOfLIS(input);


    return 0;
}



