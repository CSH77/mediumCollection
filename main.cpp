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

        //sort by first element
        typedef function<bool(vector<int>,vector<int> )> Comperator;
        Comperator comp = [](vector<int> elem1, vector<int> elem2)
        {
            return elem1[0] < elem2[0];
        };
        sort(intervals.begin(), intervals.end(), comp);

        //use priority queue keep update end time.
        priority_queue<int, vector<int>, greater<int>> pque;
        pque.push(intervals[0][1]);

        for(int i = 1; i < intervals.size(); i++)
        {
            int current = pque.top();
            if(current <= intervals[i][0]) //previous meeting is done, free to use meeting room now.
            {
                pque.pop();
                pque.push(intervals[i][1]);
            }
            else //meeting room is still being used, need another meeting room.
            {
                pque.push(intervals[i][1]);
            }
        }

        return pque.size();

        // for(vector<int> v : intervals)
        // {
        //     for(int n : v)
        //         cout << n << ":";
        //     cout << "    ";
        // }
        // cout << endl;
    }
};

int main()
{
    // vector<vector<int>> input = {{0, 30},{5, 10},{15, 20}}; //expect 2
    // vector<vector<int>> input = {{7,10},{2,4}}; //expect 1
    vector<vector<int>> input = {{13,15},{1,13}}; //expect 1

    Solution obj;
    cout << obj.minMeetingRooms(input);

    return 0;
}



