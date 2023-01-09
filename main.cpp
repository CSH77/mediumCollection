#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    double dfs(unordered_map< string, vector<pair<string, int>> >& umap, vector<string>& queries)
    {

    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        //construct graph
        unordered_map< string, vector<pair<string, int>> > umap;

        //find total possible pointsset.insert(to_string(subItem[0]));
        set<string> sset;
        for(auto item : equations)
        {
            for(auto subItem : item)
            {
                sset.insert(subItem);
            }
        }

        //cout << sset.size() << endl;
        for(auto item : sset)
        {
            umap.insert(make_pair(item, vector<pair<string, int>>{}));
        }

        for(int i = 0; i < equations.size(); i++)
        {
            //point a to b
            string pointFrom = equations[i][0];
            string pointTo = equations[i][1];
            double distance = values[i];
            pair<string, int> p = {pointTo, distance};
            vector<pair<string, int>> temp = umap[pointFrom];
            temp.push_back(p);

            //point a to b
            pointFrom = equations[i][1];
            pointTo = equations[i][0];
            distance = 1 / values[i];
            p = {pointTo, distance};
            temp = umap[pointFrom];
            temp.push_back(p);
        }

        return vector<double>{};
    }
};

int main()
{
    vector<vector<string>> equation = {{"a","b"},{"b","c"}};
    vector<double> values = {2.0, 3.0};
    vector<vector<string>> queries = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};

    Solution obj;
    vector<double> anser = obj.calcEquation(equation, values, queries);



    return 0;
}



