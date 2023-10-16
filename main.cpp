#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;


// struct comp {
//     template <typename T>

//     // Comparator function
//     bool operator()(const T& l, const T& r) const
//     {
//         if (l.second != r.second) {
//             return l.second < r.second;
//         }
//         return l.first < r.first;
//     }
// };

int main()
{
    map<int,char> mymap;

    mymap.insert(make_pair(1,'e'));
    mymap.insert(make_pair(2,'d'));
    mymap.insert(make_pair(3,'c'));
    mymap.insert(make_pair(4,'b'));
    mymap.insert(make_pair(6,'a'));

    for(auto item : mymap)
        cout << item.first << ":" << item.second << endl;

    //sort by value
    auto comp = [](pair<int, char>& a, pair<int, char>& b){
        return a.second < b.second;
    };


    // === sort with set ===========================================
    // set<pair<int,char>, comp> myset(mymap.begin(), mymap.end());
    // for(auto item : mymap)
    //     myset.insert(item);

    // cout << endl;
    // for(auto item : myset)
    //     cout << item.first << ":" << item.second << endl;
    // === sort with set ===========================================

    vector<pair<int, char>> vec(mymap.begin(), mymap.end());

    sort(vec.begin(), vec.end(), comp);

    cout << endl;
    for(auto item : vec)
        cout << item.first << ":" << item.second << endl;



    return 0;
}



