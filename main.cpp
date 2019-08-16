#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS( vector<int> &nums ) {
        set<int> lis;
        for ( auto num : nums )
        {
            if( lis.count( num ) )
                continue;

            lis.insert( num );
            auto it = lis.upper_bound( num );
            if( it != lis.end() )
                lis.erase( it );
        }
        return lis.size();
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



