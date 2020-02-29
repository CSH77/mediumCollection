#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <functional>
#include <queue>

using namespace std;

class Solution {
public:

    struct CustomCompare
    {
        bool operator()(const pair<int,int>& elem1, const pair<int,int>& elem2)
        {
                if( elem1.second < elem2.second )
                    return true;
                else if (elem1.second == elem2.second)
                {
                    if(elem1.first > elem2.first)
                        return true;
                    else
                        return false;
                }
                else
                    return false;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        //use hash to keep count of each number.
        vector<int> answer;
        map<int,int> mmap;
        for(int i = 0; i < nums.size(); i++)
        {
            //exist in data base already?
            auto search = mmap.find(nums[i]);
            if(search != mmap.end()) //it exist already, need to count up
                search->second += 1;
            else  //does not exist, add with count 1
                mmap.insert(pair<int,int>(nums[i], 1));
        }

        //hmm.. not working..
        // //use heap or priority_queue to sort them by occurance and key value
        // auto comp = [](const pair<int,int>& elem1, const pair<int,int>& elem2){
        //     if( elem1.second < elem2.second )
        //         return true;
        //     else if (elem1.second == elem2.second)
        //     {
        //         if(elem1.first > elem2.first)
        //             return true;
        //         else
        //             return false;
        //     }
        //     else
        //         return false;
        // };

        priority_queue< pair<int,int>, std::vector< pair<int,int> >, CustomCompare> pque;
        // priority_queue<pair<int,int> , std::vector<pair<int,int> >, decltype(comp)> pque; //not working somehow.

        for(auto m : mmap)
            pque.push(m);

        for(int i = 0; i < k; i++)
        {
            int n = pque.top().first;
            pque.pop();
            answer.push_back(n);
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



