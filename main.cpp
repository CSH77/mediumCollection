#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1

Example 2:

Input:
11000
11000
00100
00011

Output: 3
 */


class Solution {
public:
    struct Point
    {
        int col;
        int row;
        Point(int x, int y) : col(x), row(y){}
    };

    int numIslands(vector<vector<char>>& grid) {

        if(grid.size() <= 0)
            return 0;

        int maxCol = grid.size();
        int maxRow = grid[0].size();
        // int visited[maxCol][maxRow];
        vector< vector<bool> > visited;

        //BFS
        queue<Point> que;

        int countIsland = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == '1') //not visited
                {
                    countIsland++;
                    que.push(Point(i,j));
                    while(!que.empty())
                    {
                        Point current = que.front();
                        que.pop();
                        grid[current.col][current.row] = '0'; //mark as visited

                        //up
                        if(current.col - 1 >= 0 && grid[current.col - 1][current.row] == '1')
                        {
                            que.push(Point(current.col - 1, current.row));
                            grid[current.col - 1][current.row] = '0';
                        }

                        //down
                        if(current.col + 1 < maxCol && grid[current.col + 1][current.row] == '1')
                        {
                            que.push(Point(current.col + 1, current.row));
                            grid[current.col + 1][current.row] = '0';
                        }

                        //left
                        if(current.row - 1 >= 0 && grid[current.col][current.row - 1] == '1')
                        {
                            que.push(Point(current.col, current.row - 1 ));
                            grid[current.col][current.row - 1] = '0';
                        }

                        //right
                        if(current.row + 1 < maxRow && grid[current.col][current.row + 1] == '1')
                        {
                            que.push(Point(current.col, current.row + 1 ));
                            grid[current.col][current.row + 1] = '0';
                        }
                    }
                }
            }
        }
        return countIsland;
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
        {'0','0','0','0','0'},
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



