#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>

using namespace std;

int main()
{
    auto comp = [](pair<int,string>& a, pair<int,string>& b){
            return a.second > b.second;
    };

    priority_queue<pair<int,string>, vector<pair<int,string>>, decltype(comp)> pque(comp);

    pque.push(make_pair(1, "f"));
    pque.push(make_pair(2, "c"));
    pque.push(make_pair(3, "d"));

    while(!pque.empty())
    {
        auto item = pque.top();
        cout << item.first << ":" << item.second << endl;
        pque.pop();
    }

    return 0;
}



