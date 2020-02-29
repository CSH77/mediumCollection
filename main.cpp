#include <iostream>
#include <vector>
#include <set>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        if(board.size() == 0 || board[0].size() == 0 )
            return true;

        for(int i = 0; i < board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++)
            {
                if(check(board, word, i, j))
                    return true;
            }
        }
        return false;
    }

    bool check(vector<vector<char>>& board, string word, int row, int col){
        if(word.length() == 0)
            return true;

        if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size())
            return false;

        if(word[0] == board[row][col])
        {
            char c = word[0];
            board[row][col]='\0'; //mark as visited
            if( check(board, word.substr(1), row + 1, col) ||
                check(board, word.substr(1), row - 1, col) ||
                check(board, word.substr(1), row, col + 1) ||
                check(board, word.substr(1), row, col - 1)
              ) return true;

            board[row][col] = c; //restore original
        }
        return false;
    }
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
        // {
        //     {'A'},
        // };

        string word = "ABCCED" ;   //return true.
        // string word = "SEE" ;   //return true.
        // string word = "ABCB";   //return false.
        //string word = "AB" ;   //return true.


        Solution obj;
        cout << obj.exist(board, word);

    return 0;
}



