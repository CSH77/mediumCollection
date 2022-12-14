#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>


using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        if(nums.size() < 2)
            return;

        //unordered_map<int, int> umap;
        auto comp = [](pair<int,int>& a, pair<int,int>& b){
            return a.first < b.first;
        };
        // priority_queue< pair<int,int>, vector<pair<int,int>>, decltype(comp)> pque(comp);
        // for(int i = 0; i < nums.size(); i++)
        // {
        //     //umap.insert(make_pair(nums[i], i));
        //     pque.push(make_pair(nums[i], i));
        // }

        //find decreasing point
        priority_queue< pair<int,int>, vector<pair<int,int>>, decltype(comp)> pque(comp);
        pque.push(make_pair(nums[nums.size() - 1], nums.size() - 1));
        int decreasingIndex = -1;
        for(int i = nums.size() - 2; i >= 0; i--)
        {
            pque.push(make_pair(nums[i], i));
            if(nums[i] <  nums[i + 1])
            {
                decreasingIndex = i;
                break;
            }
        }


        // priority_queue< pair<int,int>, vector<pair<int,int>>, decltype(comp)> pque(comp);
        // for(int i = 0; i < nums.size(); i++)
        // {
        //     //umap.insert(make_pair(nums[i], i));
        //     pque.push(make_pair(nums[i], i));
        // }


        //if there is no decreasing Point give first element.
        if(decreasingIndex == -1)
        {
            sort(nums.begin(), nums.end());
            return;
        }


        //swap with bigger index, just bigger than decreasingIndex point.
        int decreasingIndexVal = nums[decreasingIndex];
        int justBiggerIndex = -1;

        auto prevQue = pque.top();
        while(!pque.empty())
        {
            // if(decreasingIndexVal == pque.top().first
            //     && decreasingIndex < pque.top().second) //prevQue is justBiggerIndex
            int cur = pque.top().first;
            if(decreasingIndexVal == cur) //prevQue is justBiggerIndex
                break;

            prevQue = pque.top();
            pque.pop();
        }

        //swap
        justBiggerIndex = prevQue.second;
        swap(nums[decreasingIndex], nums[justBiggerIndex]);

        //sort after decreasingIndex;
        auto iter = nums.begin();
        sort(iter + decreasingIndex + 1, nums.end());

    }
};

int main()
{
    Solution obj;
    //vector<int> input = {3,2,1};
    //vector<int> input = {1,2,3};
    vector<int> input = {2,3,1}; //3,1,2
    //vector<int> input = {1,3,2}; //2,1,3
    //vector<int> input = {2,1,3}; //2,3,1

    obj.nextPermutation(input);

    for(auto item : input)
        cout << item <<",";


    return 0;
}



