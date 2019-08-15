#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> paths(m, vector<int>(n));
        paths[0][0] = 1; // init

        for(size_t i = 1; i < m; i++)
            { paths[i][0] += paths[i-1][0]; } // first row update

        for(size_t j = 1; j < n; j++)
            { paths[0][j] += paths[0][j-1]; } // first col update

        // for(vector<int> v : paths)
        // {
        //     for( int n : v)
        //         cout << n << " ";
        //     cout << endl;
        // }
        // cout << endl;

        for(size_t i = 1; i < m; i++)
        {
           for(size_t j = 1; j < n; j++)
           {
               paths[i][j] += paths[i-1][j] + paths[i][j-1];
           }
        }
        return paths[m-1][n-1];

        // return -1;
    }
};

int main()
{
    Solution obj;
    cout << obj.uniquePaths(2,3);

    return 0;
}



