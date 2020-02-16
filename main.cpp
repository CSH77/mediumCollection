#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int answer = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            answer = answer ^ nums[i];
        }
        return answer;
    }
};

int main()
{
    vector<int> input = {4,1,2,1,2};

    Solution obj;
    cout << obj.singleNumber(input) << endl;

    return 0;
}



