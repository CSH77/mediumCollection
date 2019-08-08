#include <iostream>
#include <vector>
#include <set>
using namespace std;

/*
Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
 */

class Solution {
public:
    vector<vector<int>> answer;

    void permuHelper(vector<int>& num, int l, int r)
    {
        if(l == r)
        {
            vector<int> temp;
            for(int n : num)
                temp.push_back(n);
            answer.push_back(temp);
            return;
        }

        for(int i = l; i < r; i++)
        {
            //swap
            swap(num[i], num[l]);

            //call recusively,
            permuHelper(num, l + 1, r);

            //swapback.
            swap(num[i], num[l]);
        }
    }//EOF

    vector<vector<int>> permute(vector<int>& nums) {
        permuHelper(nums, 0, nums.size());
        return answer;
    }
};

int main()
{
    vector<int> input = {1,2,3};

    Solution obj;
    vector<vector<int>> answer = obj.permute(input);

    for(vector<int> v : answer)
    {
        for(int n : v)
            cout << n << " ";
        cout << endl;
    }



    return 0;
}



