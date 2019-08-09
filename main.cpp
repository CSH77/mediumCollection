#include <iostream>
#include <vector>
#include <set>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
/*
Word Search

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
 */

class Solution {
public:
    struct Point
    {
        char val;
        int col;
        int row;
        Point(char v, int c, int r) : val(v), col(c), row(r){}
    };

    bool exist(vector<vector<char>>& board, string word) {

        //starting point.
        int startIndex = 0;
        char start = word[startIndex];
        int next = 0;

        int maxCol = board.size();
        int maxRow = board[0].size();

        int visited[maxCol][maxRow];
        for(int i = 0; i < maxCol; i++)
        {
            for(int j = 0; j < maxRow; j++)
                visited[i][j] = 0;
        }

        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[i].size(); j++)
            {
                stack<Point> stk;
                if(board[i][j] == start) //found starting point
                {
                    stk.push(Point(board[i][j], i, j));
                    next = 0;
                }

                while(!stk.empty())
                {
                    if(stk.size() == word.size())
                        return true;

                    Point current = stk.top();
                    stk.pop();
                    next++;

                    int val = current.val;
                    int col = current.col;
                    int row = current.row;
                    visited[col][row] = 1;

                    //up
                    if(col - 1 >=0 && board[col - 1][row] == word[next] && visited[col - 1][row] == 0)
                    {
                        stk.push(current);
                        stk.push( Point( board[col - 1][row], col - 1, row ) );
                    }
                    else if(col + 1 < maxCol && board[col + 1][row] == word[next] && visited[col + 1][row] == 0 ) //down
                    {
                        stk.push(current);
                        stk.push( Point( board[col + 1][row], col + 1, row ) );
                    }
                    else if(row - 1 >= 0 && board[col][row - 1] == word[next] && visited[col][row - 1] == 0) //left
                    {
                        stk.push(current);
                        stk.push( Point( board[col][row -1], col, row - 1 ) );
                    }
                    else if(row + 1 >= 0 && board[col][row + 1] == word[next] && visited[col][row + 1] == 0) //right
                    {
                        stk.push(current);
                        stk.push( Point( board[col][row + 1], col, row + 1 ) );
                    }
                    else
                        next--;
                }//while
            }//for
        }//for
        return false;

    }//EOF
};


int main()
{
    vector<vector<char>> board =
        {
            {'A','B','C','E'},
            {'S','F','C','S'},
            {'A','D','E','E'}
        };

    // vector<vector<char>> board =
    //     {
    //         {'A'},
    //     };

        string word = "ABCCED" ;   //return true.
        // string word = "SEE" ;   //return true.
        // string word = "ABCB";   //eturn false.
        // string word = "AB" ;   //return true.


        Solution obj;
        cout << obj.exist(board, word);

    return 0;
}



