#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <functional>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
            for(auto item : nums)
            {
                auto search = umap.find(item);
                if(search != umap.end()) //increase count
                {
                    search->second++;
                }
                else //first element, insert
                {
                    umap.insert(make_pair(item, 1));
                }
            }

        auto comp = [](pair<int,int>& a, pair<int,int>& b){
            return a.second < b.second;
        };

        //use priority queue sort by element count
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pque(comp);

        for(auto item : umap)
        {
            pque.push(make_pair(item.first, item.second));
        }

        vector<int> answer;
        for(int i = 0; i < k; i++)
        {
            answer.push_back(pque.top().first);
            pque.pop();
        }

        return answer;
    }//EOF
};

int main()
{
    // vector<int> input = {1,1,1,2,2,2,3,3,3}; //and 3, expected 1,3,2
    vector<int> input = {1,1,1,2,2,3}; //and 2, expected 1,3,2
    // vector<int> input = {1,2};

    Solution obj;
    vector<int> vec = obj.topKFrequent(input, 2);

    for(int n : vec)
        cout << n <<" ";
    cout << endl;

    return 0;
}



