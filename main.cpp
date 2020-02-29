#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // vector<vector<int>> answer;
        //sort by first element
        if(intervals.empty())
            return intervals;


        auto comp = [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        };

        sort(intervals.begin(), intervals.end(), comp);

        // for(vector<int> n : intervals)
        // {
        //     cout << n[0] << ":" << n[1] << " ";
        // }
        // cout << endl;

        int cur = 0;
        int next = 0;
        while(next < intervals.size())
        {
            //check if intervals is overrapping
            vector<int> first = intervals[cur];
            vector<int> second = intervals[next];

            int newLeft = 0;
            int newRight = 0;
            if(first[1] >= second[0]) //overrapping, merge required
            {
                if(first[1] <= second[1])
                    newRight = second[1];
                else
                    newRight = first[1];

                //merge two element
                newLeft = first[0];
                // answer.push_back(vector<int>{newLeft, newRight});
                intervals[cur][0] = newLeft;
                intervals[cur][1] = newRight;
                next = next + 1;
            }
            else //two elements are not orverraped,
            {
                // answer.push_back(intervals[i - 1]);
                cur++;
                intervals[cur] = intervals[next];
            }

        }
        vector<vector<int>> answer(intervals.begin(), intervals.begin() + cur + 1);
        return answer;
    }
};

int main()
{
    // vector<vector<int>> input = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> input = {{1,4},{0,4}};
    Solution obj;
    vector<vector<int>> answer = obj.merge(input);


    for(auto v : answer)
    {
        for(auto vv : v)
        {
            cout << vv <<",";
        }
        cout << "   ";
    }

    return 0;
}



