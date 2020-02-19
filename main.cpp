#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mmap; //value, index number
        for(int i = 0; i < nums.size(); i++)
            mmap.insert({nums[i], i});

        //find target combination
        for(int i = 0; i < nums.size(); i++)
        {
            int numberNeeded = target - nums[i];

            //find nessasary number, occurance must be more than one.
            auto search = mmap.find(numberNeeded);
            if(search != mmap.end() && search->second != i) //it can not be same value
                return vector<int>{i, search->second};
        }
        return vector<int>{};
    }
};

int main()
{
    // vector<int> input = {2, 7, 11, 15};
    vector<int> input = {3,2,4}; //expect 1,2
    Solution obj;
    vector<int> answer = obj.twoSum(input, 6);

    for(auto v : answer)
        cout << v << " ";
    cout << endl;

    return 0;
}



