#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>
#include <queue>
#include <map>
#include <unordered_map>
#include <functional>

using namespace std;
struct compa {
  bool operator() ( pair<char, int> &a,  pair<char, int> &b){
      return a.second < b.second;
  }
};
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //count each task
        unordered_map<char, int> mmap;
        int total = 0;
        for(auto c : tasks)
        {
            auto search = mmap.find(c);
            if(search != mmap.end()) //exist, just count up
                search->second += 1;
            else //non exist, add with count 1;
                mmap.insert(pair<char, int>{c, 1});
        }

        // //priority que
        // typedef function<bool(pair<char, int>, pair<char, int>)> Comperator;        
        // Comperator comp = [](pair<char, int> a, pair<char, int> b) 
        // {
        //     return a.second < b.second;
        // };

        priority_queue<pair<char, int>, vector<pair<char,int>>, compa> pque;

        //insert pair to que.
        for(auto iter = mmap.begin(); iter != mmap.end(); iter++)
        {
            pque.push(make_pair(iter->first, iter->second));
        }

        vector<pair<char,int>> vec;

        while(!pque.empty())
        {
            int k = n;
            vec.clear();
            while(k >= 0)
            {
                bool pushed = false;
                if(!pque.empty())
                {
                    pair<char,int> top = pque.top();
                    pque.pop();
                    top.second -= 1;
                    if(top.second > 0)
                        vec.push_back(top);
                    pushed = true;
                }
                k--;
                if(pushed || vec.size() > 0)
                    total++;
            }
            for(auto &n : vec)
                pque.push(n);
        }
        return total;
    }
};

int main()
{
    vector<char> input = {'A','A','A','B','B','B'}; //expect 8

    Solution obj;
    cout << obj.leastInterval(input, 2);

    return 0;
}



