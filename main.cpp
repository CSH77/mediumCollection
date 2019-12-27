#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        if(strs.empty())
            return vector<vector<string>>{};

        // if(strs.size() < 1)
        //     return vector<vector<string>>{};

        vector<vector<string>> answer;

        multimap<string, string> mmap;

        for(int i = 0; i < strs.size(); i++)
        {
            //find total value of string.
            // int total =  0;
            // for(auto c : strs[i])
            //     total += c;

            // mmap.insert(make_pair(total, strs[i]));
            //sort string before use it as a key.
            string curStringKey = strs[i];
            sort(curStringKey.begin(), curStringKey.end());
            mmap.insert(make_pair(curStringKey, strs[i]));
        }

        string key = "000";
        for( auto iter = mmap.begin(); iter != mmap.end(); iter++)
        {

            if(iter->first != key)
            {
                vector<string> strVec;
                key = iter->first;
                typedef multimap<string, string>::iterator rangeIter;
                pair<rangeIter, rangeIter> result = mmap.equal_range(key);

                for(rangeIter it = result.first; it != result.second; it++)
                {
                    strVec.push_back(it->second);
                }

                //push to answer vector
                answer.push_back(strVec);
            }
        }

        return answer;
    }
};

int main()
{
    vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
    // vector<string> input = {"cab","tin","pew","duh","may","ill","buy","bar","max","doc"};
    // vector<string> input = {""};

    Solution obj;
    vector<vector<string>> answer = obj.groupAnagrams(input);

    for(auto v : answer)
    {
        for(auto vv : v)
            cout << vv << " ";
        cout << endl;
    }


    return 0;
}



