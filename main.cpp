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
        int row = matrix.size() - 1;;
        int col = 0;

        while(row >= 0 && col < matrix[0].size())
        {
            int current = matrix[row][col];

            if(current == target)
                return true;

            if(current > target) //find row first
            {
                row--;
            }
            else //now current is smaller than target, iterate coloumn means increasing target value
            {
                col++;
            }
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

    Solution obj;
    // cout << obj.searchMatrix(input, 5) << endl; //expect true;
    cout << obj.searchMatrix(input, 25) << endl; //expect false;

    return 0;
}



