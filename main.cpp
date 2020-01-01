#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

class Solution {
public:
    struct Point
    {
        int row;
        int col;
        Point(int y, int x) : row(y), col(x){}
    };

    int numIslands(vector<vector<char>>& grid) {

        if(grid.size() <= 0)
            return 0;

        int numOfIsland = 0;

        //use BFS
        int maxRow = grid.size();
        int maxCol = grid[0].size();

        queue<Point> que;

        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == '1') //found island
                {
                    numOfIsland++;
                    que.push(Point(i,j));
                    while(!que.empty())
                    {
                        Point curPtr = que.front();
                        que.pop();
                        grid[curPtr.row][curPtr.col] = '0'; //mark as visited

                        //up
                        if(curPtr.row > 0 && grid[curPtr.row - 1][curPtr.col] == '1')
                        {
                            que.push(Point(curPtr.row - 1, curPtr.col));
                            grid[curPtr.row - 1][curPtr.col] = '0';
                        }

                        //down
                        if(curPtr.row + 1 < maxRow && grid[curPtr.row + 1][curPtr.col] == '1')
                        {
                            que.push(Point(curPtr.row + 1, curPtr.col));
                            grid[curPtr.row + 1][curPtr.col] = '0';
                        }

                        //left
                        if(curPtr.col > 0 && grid[curPtr.row][curPtr.col - 1] == '1')
                        {
                            que.push(Point(curPtr.row, curPtr.col - 1));
                            grid[curPtr.row][curPtr.col - 1] = '0';
                        }

                        //right
                        if(curPtr.col + 1 < maxCol && grid[curPtr.row][curPtr.col + 1] == '1')
                        {
                            que.push(Point(curPtr.row, curPtr.col + 1));
                            grid[curPtr.row][curPtr.col + 1] = '0';
                        }
                    }
                }
            }
        }
        return numOfIsland;
    }
};


int main()
{
/*
    Input:
    11110
    11010
    11000
    00000
 */
    vector< vector<char> > input =
    {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','1','0'},
    };

    Solution obj;
    cout << obj.numIslands(input);


    // for( vector<char> v : input)
    // {
    //     for(char c : v)
    //         cout << c << " ";
    //     cout << endl;
    // }



    return 0;
}



