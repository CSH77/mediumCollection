#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> answer;

    void permuHelper(vector<int>& num, int l, int r)
    {
        if(l == r)
        {
            vector<int> temp;
            for(auto n : num)
                temp.push_back(n);

            answer.push_back(temp);
            return;
        }

        for(int i = l; i < r; i++)
        {
            swap(num[i], num[l] );
            permuHelper(num, l + 1, r);
            swap(num[i], num[l] ); //swap back
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



