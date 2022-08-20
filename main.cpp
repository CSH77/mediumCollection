#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <functional>
#include <queue>
#include <unordered_map>
#include "include/Solution.h"

using namespace std;

int main()
{
    // vector<int> input = {1,1,1,2,2,2,3,3,3}; //and 3, expected 1,3,2
    vector<int> input = {1,1,1,2,2,3}; //and 2, expected 1,3,2
    // vector<int> input = {1,2};

    Solution obj;
    vector<int> vec = obj.topKFrequent(input, 2);

    for(int n : vec)
        cout << n <<" ";
    cout << endl;

    return 0;
}
