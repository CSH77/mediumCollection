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
        answer.push_back(vector<int>());
        vector<int> current;
        set<int> myset;

        subsetHelper(nums, answer, current, myset);

        return answer;
    }

    void subsetHelper(vector<int>& nums, vector<vector<int>>& answer, vector<int> current, set<int> myset)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (myset.find(nums[i]) != myset.end()) //alrady exist, do not use this number
                continue;

            //never used, use this number
            myset.insert(nums[i]);
            subsetHelper(nums, answer, current, myset);

            current.push_back(nums[i]);
            answer.push_back(current);
        }
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



