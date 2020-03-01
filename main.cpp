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

        //sort by first
        auto comp = [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        };
        sort(intervals.begin(), intervals.end(), comp);

        //use priority_que que holds end time of each room, check if starting time is conflict with end time
        priority_queue<int, vector<int>, greater<int>> pque;
        pque.push(intervals[0][1]); //push end time

        for(int i = 1; i < intervals.size(); i++)
        {
            int roomOccupiedEndTime = pque.top();
            int roomToReserveStartTime = intervals[i][0];
            if(roomOccupiedEndTime <= roomToReserveStartTime) //now room is free to use
            {
                pque.pop();
                pque.push(intervals[i][1]); //reseve with end time
            }
            else  //room is not free yet, need another room
            {
                pque.push(intervals[i][1]);
            }
        }
        return pque.size();
    }
};

int main()
{
    vector<vector<int>> input = {{0, 30},{5, 10},{15, 20}}; //expect 2
    // vector<vector<int>> input = {{7,10},{2,4}}; //expect 1
    // vector<vector<int>> input = {{13,15},{1,13}}; //expect 1

    Solution obj;
    cout << obj.minMeetingRooms(input);

    return 0;
}



