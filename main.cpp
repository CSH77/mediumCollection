#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

uint32_t reverseBit(uint32_t num, int start, int end)
{
    uint32_t numToReverse = num >> start;
    numToReverse = numToReverse << (32 - (end - start + 1) );
    numToReverse = numToReverse >> (32 - (end - start + 1) );

    vector<int> reverseNumVac;
    while(numToReverse)
    {
        int num = numToReverse & 1 == 1 ? 1 : 0;
        reverseNumVac.push_back(num);
        numToReverse = numToReverse >> 1;
    }

    reverse(reverseNumVac.begin(), reverseNumVac.end());
    for(auto item : reverseNumVac)
        cout << item;
    cout << endl;

    int temp = num;
    cout << temp << endl;
    vector<int> myvec;
    while(temp)
    {
        int num = temp & 1 == 1 ? 1 : 0;
        myvec.push_back(num);
        temp = temp >> 1;
    }
    cout << endl;

    int reverseNumIndex = 0;
    for(int i = start; i <= end; i++)
    {
        myvec[i] = reverseNumVac[reverseNumIndex++];
    }

    //make number from vector
    int answer = 0;
    for(int i = 0; i < myvec.size(); i++)
    {
        answer = answer + myvec[i];
        answer = answer << 1;
    }

    for(auto item : myvec)
        cout << item;
    cout << endl;

    return answer;
}

int main()
{
    //40 dec = 00101000
    //should be converted to 10100 = 20
    cout << reverseBit(40, 2, 5);

    return 0;
}
