#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> answer;
    void permuHelper(vector<int>& nums, int left, int right){
        if(left > right)
            return;
        if(left == right)
        {
            answer.push_back(nums);
            return;
        }

        for(int i = left; i < right; i++)
        {
            swap(nums[i], nums[left]);
            permuHelper(nums, left + 1, right);
            swap(nums[i], nums[left]);
        }
    }

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



