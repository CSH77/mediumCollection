#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS( vector<int>& nums ) {
        if(nums.size() < 1)
            return 0;

        vector<int> answer(nums.size(), 1);

        for(int i = 1; i < nums.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[j] < nums[i]) //subsequence
                    answer[i] = max(answer[i], answer[j] + 1);
            }
        }

        //sort vector to find maximum number.
        auto comp = [](int a, int b){
            return a > b;
        };
        sort(answer.begin(), answer.end(), comp);

        return answer[0];

    }
};

int main()
{
    // vector<int> input = {10,9,2,5,3,7,101,18}; //expect 4   {2,3,7,101}
    vector<int> input = {3,4,-1, 0, 6, 2, 3}; //expect  4   {-1, 0, 2, 3}

    Solution obj;
    cout << obj.lengthOfLIS(input);


    return 0;
}



