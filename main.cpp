#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> current;
        backtrack(answer, nums, current, 0);
        return answer;
    }

    void backtrack(vector<vector<int>>& answer, vector<int>& nums, vector<int> cur, int index)
    {
        answer.push_back(cur);
        for(int i = index; i < nums.size(); i++)
        {
            vector<int> temp = cur;
            temp.push_back(nums[i]);
            backtrack(answer, nums, temp, i + 1);
        }

        return;
    }
};
int main()
{
    Solution obj;
    vector<int> input = {1,2,3};

    vector<vector<int>> answer = obj.subsets(input);

    for(auto item : answer)
    {
        for(auto subItem : item)
        {
            cout << subItem <<" ";
        }
        cout << " ,    ";
    }

    return 0;
}



