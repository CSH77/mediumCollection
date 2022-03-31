#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        auto comp = [](pair<int,int>& a, pair<int,int>& b){
            return a.second < b.second;
        };

        pair<int,int> answerPair = make_pair(nums[0],1); //second as count, first as index

        map<int, int> mymap;
        for(auto item : nums)
        {
            auto search = mymap.find(item);
            if(search != mymap.end()) //exist, add count
            {
                search->second++;
                if(search->second > answerPair.second)
                    answerPair = make_pair(search->first, search->second);
            }
            else //add new
                mymap.insert(make_pair(item, 1));
        }

        //find most frequent Element by sorting.
        //sort map by 2nd element.
        // priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pque(comp);

        // for(auto item : mymap)
        //     pque.push(make_pair(item.first, item.second));

        // return pque.top().first;

        return answerPair.first;

    }
};

int main()
{
    Solution obj;
    vector<int> input = {2,2,1,1,1,2,2};
    cout << obj.majorityElement(input);

    return 0;
}



