#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>
#include <queue>
#include <map>

using namespace std;

struct comp {
  bool operator() ( pair<char, int> &a,  pair<char, int> &b){
      return a.second < b.second;
  }
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> dict;
        int retval = 0;
        for(auto &n: tasks)
        	dict[n]++;
        priority_queue<pair<char, int>, vector<pair<char,int>>, comp> q;

        for(auto it = dict.begin(); it != dict.end(); ++it)
        {
            q.push(make_pair(it->first, it->second));
        }

        vector<pair<char, int>> Tasks;

        /*Idea is to assign most frequently occuring char first
        Since after assignment some other char may become the highest frequency
        char we need a priority queue to keep the highest freq char on top of the list
        Then assign the char, decrement the freq count of the char and increment
        the total cpu cycles (retval). If PQ is empty increment the retval as it will ne
        the idle state. Add back the <char,freq> pair to the PQ if freq is > 0.
        Edge case when last element has been added, do not put idle cycles after that.*/

        while(!q.empty()) {
            int k = n;
            Tasks.clear();
            while(k >= 0) {
                bool pushed = false;
                if(!q.empty()) {
                    pair<char, int> top = q.top();
                    q.pop();
                    top.second--;
                    if(top.second > 0)
                        Tasks.push_back(top);
                    pushed = true;
                }
                k--;
                if(pushed || Tasks.size() > 0) retval++;
            }
            for(auto &n: Tasks) q.push(n);
        }
        return retval;
    }
};

int main()
{
    vector<char> input = {'A','A','A','B','B','B'}; //expect 8

    Solution obj;
    cout << obj.leastInterval(input, 2);

    return 0;
}



