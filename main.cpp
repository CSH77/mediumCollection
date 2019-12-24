#include <iostream>
#include <set>
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:

    void setZeroColRow(vector<vector<int>>& matrix, int curRow, int curCol)
    {
        int maxRow = matrix.size();
        int maxCol = matrix[0].size();

        //set all row of curRow as 0
        for(int i = 0; i < maxRow; i++)
        {
            matrix[i][curCol] = 0;
        }

        //set all col of curCol as 0
        for(int i = 0; i < maxCol; i++)
        {
            matrix[curRow][i] = 0;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {

        vector<pair<int,int>> vec;

        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[i].size(); j++)
            {
                //if maxtrix is zero, record it
                if(matrix[i][j] == 0)
                {
                    vec.push_back(make_pair(i,j));
                }
            }
        }

        for(int i = 0; i < vec.size(); i++)
        {
            setZeroColRow(matrix, vec[i].first,vec[i].second );
        }

    }
};

int main()
{

    // vector< vector<int> > input =
    // {
    //     {0,1,2,0},
    //     {3,4,5,2},
    //     {1,3,1,5}
    // };

    vector< vector<int> > input =
    {
        {0,1,2,0},
        {3,4,5,2},
        {1,3,1,5}
    };

    for(auto v : input)
    {
        for(auto vv : v)
            cout << vv << " ";
        cout << endl;
    }
    cout << endl;

    Solution obj;
    obj.setZeroes(input);

    for(auto v : input)
    {
        for(auto vv : v)
            cout << vv << " ";
        cout << endl;
    }

    return 0;
}

