#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> strOrder;

    //return 1 if first argument is smaller,
    //return 2, if second argument is smaller,
    //return 0, if they are same
    int compareStr(string a, string b)
    {
        int minSize = min(a.size(), b.size());

        for(int i = 0; i < minSize; i++)
        {
            if( strOrder[ a[i] ] < strOrder [ b[i] ] ) //smaller is the first
                return 1; //a is smaller.
            else if(strOrder[ a[i] ] > strOrder[ b[i] ]) // b is smaller
                return 2;
        }

        //same value so far, detemine which is smaller by their size
        if(a.size() < b.size())
            return 1;
        else if (a.size() > b.size())
            return 2;
        else
            return 0;

        return -1;
    }


    bool isAlienSorted(vector<string>& words, string order) {
        //assign number to each string

        if(words.size() <= 1)
            return true;

        strOrder.clear();
        strOrder.resize(255, 0);

        //give value to each character order
        for(int i = 0; i < order.size(); i++)
            strOrder[order[i]] = i;

        // for(int i = 0; i < order.size(); i++)
        // {
        //     cout << order[i] << ": " <<  strOrder[order[i]] << endl;
        // }

        //compare,
        for(int i = 1; i < words.size(); i++)
        {
            int comp = compareStr(words[i], words[i-1]); //expect 2
            if(comp == 1)
                return false;
        }

        return true;

        // for(int i = 0; i < order.size(); i++)
        // {
        //     cout << order[i] << ": " <<  strOrder[order[i]] << endl;
        // }

    }
};

int main()
{
    // string order = "hlabcdefgijkmnopqrstuvwxyz"; //expect true;
    // vector<string> words = {"hello","leetcode"};

    // string order = "worldabcefghijkmnpqstuvxyz"; //expect false;
    // vector<string> words = {"word","world","row"};

    string order = "abcdefghijklmnopqrstuvwxyz"; //expect false;
    vector<string> words = {"apple","app"};

    Solution obj;
    bool answer = obj.isAlienSorted(words, order);

    cout << answer << endl;

    return 0;
}



