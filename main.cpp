#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty())
            return intervals;
        vector<vector<int>> answer;

        //sort by 1st element
        auto comp = [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        };
        sort(intervals.begin(), intervals.end(), comp);

        answer.push_back(intervals[0]);
        for(int i = 0; i < intervals.size(); i++)
        {
            vector<int> temp = answer[answer.size() - 1 ];
            if( temp[1] >= intervals[i][0] ) //merge
            {
                temp[1] = max(temp[1],intervals[i][1]);
                answer.erase(answer.end());
                answer.push_back(temp);
            }
            else //no need to merge
            {
                answer.push_back(intervals[i]);
            }
        }
        return answer;
    }
};

int main()
{
    vector<vector<int>> input = {{1,3},{2,6},{8,10},{15,18}};
    // vector<vector<int>> input = {{1,4},{0,4}};
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



