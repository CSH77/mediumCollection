#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> paths(m, vector<int>(n));
        paths[0][0] = 1; // init

        //initialize first row
        for(int i = 0; i < paths[0].size(); i++)
            paths[0][i] = 1;

        //initialize first col
        for(int i = 0; i < paths.size(); i++)
            paths[i][0]  = 1;

        for(int i = 1; i < paths.size(); i++)
        {
            for(int j = 1; j < paths[i].size(); j++)
                paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
        }

        return paths[paths.size() - 1][paths[0].size() - 1];
    }
};

int main()
{
    Solution obj;
    cout << obj.uniquePaths(2,3);

    return 0;
}



