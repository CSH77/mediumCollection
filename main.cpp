#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    vector<vector<int>> answer;

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() < 1)
            return intervals;

        //sort interval by its first element.
        vector<pair<int,int>> temp;
        for(int i = 0; i < intervals.size(); i++)
        {
            temp.push_back(make_pair(intervals[i][0], intervals[i][1]));
        }

        //sort temp vector by its first element
        auto comp = [](pair<int,int>& a, pair<int,int>& b){
            return a.first < b.first;
        };

        sort(temp.begin(), temp.end(), comp);
        //copy back to original
        intervals.clear();

        for(int i = 0; i < temp.size(); i++)
        {
            intervals.push_back({temp[i].first, temp[i].second});
        }


        vector<vector<int>> answer;
        answer.push_back(intervals[0]);
        int answerIndex = 0;
        for(int i = 0; i < intervals.size(); i++)
        {
            if (  (intervals[i][0] >= answer[answerIndex][0] && intervals[i][0] <= answer[answerIndex][1]) ||
                  (intervals[i][1] >= answer[answerIndex][0] && intervals[i][1] <= answer[answerIndex][1]) ||
                  (answer[answerIndex][0] >= intervals[i][0] && answer[answerIndex][0] <= intervals[i][1]) ||
                  (answer[answerIndex][1] >= intervals[i][0] && answer[answerIndex][1] <= intervals[i][1])
                ) //overlap, merge
            {
                //decide min
                int min = (intervals[i][0] < answer[answerIndex][0]) ? intervals[i][0] : answer[answerIndex][0];

                //decide max
                int max = (intervals[i][1] > answer[answerIndex][1]) ? intervals[i][1] : answer[answerIndex][1];

                vector<int> temp;
                temp.push_back(min);
                temp.push_back(max);
                answer.pop_back();
                answer.push_back(temp);
            }
            else //does not overlap.. just add from interval.
            {
                answer.push_back(intervals[i]);
                answerIndex++;
            }
        }

        return answer;
    }
};

int main()
{
    vector<vector<int>> input = {{1,3},{2,6},{8,10},{15,18}};

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



