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

        map<string, vector<string>> anagramsGroup;
        for(int i = 0; i < strs.size(); i++)
        {
            string word = strs[i];
            //sort word, use it as a key.
            sort(word.begin(), word.end());

            //if word is in anagramGroup, add it.
            auto search = anagramsGroup.find(word);
            if(search != anagramsGroup.end()) //the word is in the database, add more.
            {
                search->second.push_back(strs[i]);
            }
            else //not exist, add as new
            {
                vector<string> temp;
                temp.push_back(strs[i]);
                anagramsGroup.insert(make_pair(word, temp));
            }
        }

        vector<vector<string>> answser;
        for(auto item : anagramsGroup)
        {
            vector<string> stringGroup;
            for(auto subitem : item.second)
            {
                stringGroup.push_back(subitem);
            }
            answser.push_back(stringGroup);
        }

        return answser;
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



