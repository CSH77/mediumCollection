#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>

using namespace std;

int main()
{
    multimap<int,int> mmap;
    mmap.insert(make_pair(1,1));
    mmap.insert(make_pair(1,2));
    mmap.insert(make_pair(1,3));
    mmap.insert(make_pair(3,1));
    mmap.insert(make_pair(3,2));
    mmap.insert(make_pair(2,1));
    mmap.insert(make_pair(2,2));

    // for(auto item : mmap)
    //     cout << item.first << "::" << item.second << endl;

    for(auto iter = mmap.begin(); iter != mmap.end(); iter = mmap.upper_bound(iter->first) )
    {
        auto iter2 = mmap.equal_range(iter->first);
        cout << "key: " << iter->first << " ";
        cout << "values: ";
        for(auto it = iter2.first; it != iter2.second; it++)
        {
            cout << it->second << " ";
        }
        cout << endl;
    }



    return 0;
}



