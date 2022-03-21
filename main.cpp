#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int maxX = matrix[0].size();
        int maxY = matrix.size();

        int x = 0, y = 0;

        while(x < maxX)
        {
            if(matrix[y][x] == target)
                return true;

            if(matrix[y][x] > target)
                break;

            x++;
        }
        if(x >= maxX)
            x = x - 1;

        while(x < maxX && y < maxY && x >= 0 && y >= 0)
        {
            int currentValue = matrix[y][x];
            if(currentValue == target)
                return true;

            if(currentValue > target)
                x = x - 1;
            else
                y = y + 1;
        }

        return false;
    }
};

int main()
{
    vector<vector<int>> input = {
                                    {1,   4,  7, 11, 15},
                                    {2,   5,  8, 12, 19},
                                    {3,   6,  9, 16, 22},
                                    {10, 13, 14, 17, 24},
                                    {18, 21, 23, 26, 30}
                                };

    // vector<vector<int>> input = { {5}, {6} }; //true

    Solution obj;
    // cout << obj.searchMatrix(input, 5) << endl; //expect true;
    // cout << obj.searchMatrix(input, 25) << endl; //expect false;

    cout << obj.searchMatrix(input, 5) << endl; //expect true;

    return 0;
}



