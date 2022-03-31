#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>

using namespace std;
/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int numberOfPeople;
    int findCelebrity(int n) {
        numberOfPeople = n;
        for(int i = 0; i < n; i++){
            if( isCelebrity(i))
                return i;
        }
        return -1;
    }

    bool isCelebrity(int i)
    {
        for(int j = 0; j < numberOfPeople; j++)
        {
            if(i == j) //know themselves, skip.
                continue;

            if( knows(i,j) || !knows(j,i))
                return false;
        }
        return true;
    }
};


int main()
{
    cout << "hello world!" << endl;

    return 0;
}



