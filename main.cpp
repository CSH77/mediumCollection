#include <iostream>
#include <set>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p1 = 0;
        int p2 = 0;
        int p3 = nums.size() - 1;

        while(p2 <= p3)
        {
            if(nums[p2] == 0)
            {
                swap(nums[p1], nums[p2]);
                p1++;
                p2++;
            }
            else if(nums[p2] == 2)
            {
                swap(nums[p2], nums[p3]);
                p3--;
            }
            else
                p2++;
        }
    }//EOF
};

int main()
{
    Solution obj;

    vector<int> input = {2,0,2,1,1,0};
    //vector<int> input = {2,0,1};
    obj.sortColors(input);

    for(int n : input)
        cout << n << " ";
    cout << endl;


    return 0;
}



