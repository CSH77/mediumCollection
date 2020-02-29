#include <iostream>
#include <set>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cur = 0;
        int left =0;
        int right = nums.size() - 1;

        while(cur <= right)
        {
            if(nums[cur] == 0)
                swap(nums[cur++], nums[left++]);
            else if(nums[cur] == 2)
                swap(nums[cur], nums[right--]);
            else
                cur++;
        }
    }//EOF
};

int main()
{
    Solution obj;

    vector<int> input = {2,0,2,1,1,0};
    obj.sortColors(input);

    for(int n : input)
        cout << n << " ";
    cout << endl;


    return 0;
}



