#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.empty())
            return 0;

        //sort by first.
        auto comp = [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        };
        sort(intervals.begin(), intervals.end(), comp);

        auto compEnd = [](vector<int>& a, vector<int>& b){
            return a[1] > b[1];
        };
        //usg priority queue sorted by end meeting time.
        priority_queue< vector<int>, vector<vector<int>>, decltype(compEnd)> pque(compEnd);

        pque.push(intervals[0]);

        for(int i = 1; i < intervals.size(); i++)
        {
            vector<int> currentInterval = intervals[i];
            vector<int> tempQue = pque.top();
            if( currentInterval[0] >= tempQue[1] ) //meeting room is free to use.
            {
                pque.pop();
                pque.push(currentInterval);
            }
            else
            {
                pque.push(currentInterval);
            }
        }

        return pque.size();

    }
};

int main()
{
    // vector<vector<int>> input = {{0, 30},{5, 10},{15, 20}}; //expect 2
    // vector<vector<int>> input = {{7,10},{2,4}}; //expect 1
    // vector<vector<int>> input = {{13,15},{1,13}}; //expect 1
    vector<vector<int>> input = {{1, 100},{20, 40},{50, 60}}; //expect 2

    Solution obj;
    cout << obj.minMeetingRooms(input);

    return 0;
}



