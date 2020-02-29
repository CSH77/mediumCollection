#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <functional>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        map<int,int> mmap;
        for(int i = 0; i < nums.size(); i++)
        {
            auto search = mmap.find( nums[i]);
            if(search != mmap.end()) //found it
            {
                //count up
                search->second += 1;
            }
            else //add new one.
            {
                mmap.insert(pair<int,int>(nums[i],1));
            }
        }

        // for(pair<int,int> p : mmap)
        //     cout << p.first << " ";


        //sort by map value
        typedef function<bool(pair<int,int>, pair<int,int> ) > Comperator;

        Comperator comp = []( pair<int,int> elem1, pair<int,int> elem2)
        {
            if( elem1.second > elem2.second )
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
        };

        set<pair<int,int>, Comperator> sset(mmap.begin(), mmap.end(), comp);

        // for(pair<int,int> p : sset)
        //     cout << p.first << " ";

        vector<int> answer;

        int current = -1;
        int count = 0;
        for(pair<int,int> p : sset)
        {
            if(count >= k)
                break;

            answer.push_back(p.first);
            count++;
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



