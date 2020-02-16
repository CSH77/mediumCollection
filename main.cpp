#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        auto ptr = nums.end() - k;
        vector<int> tmp = vector<int>(ptr,nums.end());
        for(int i = nums.size() - k - 1; i>=0; i--){
            nums[i+k] = nums[i];
        }
        for(int i=0;i<k;i++){
            nums[i] = tmp[i];
        }
    }
};


int main()
{
    vector<int> nums = {1,2,3,4,5,6,7};

    Solution obj;
    obj.rotate(nums, 3); //expect 5,6,7,1,2,3,4 with 3


    for(auto v : nums)
        cout << v << " ";
    cout << endl;

    return 0;
}



