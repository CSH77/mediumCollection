#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>

using namespace std;
/* The knows API is defined for you.
      bool knows(int a, int b); */

bool knows(int a, int b){
    return true;
};

class Solution {
public:
    int numberOfPeople;
    int findCelebrity(int n) {
        numberOfPeople = n;

        int possibleCelebrity = 0;


        for(int i = 0; i < n; i++)
        {
            if(knows(possibleCelebrity, i)) //possibleCelebrity is i now.
                possibleCelebrity = i;
            //else //next will be possible celebrity

        }
        if( isCelebrity(possibleCelebrity))
            return possibleCelebrity
        else
            return -1;

        //check possible celebrity if the celebrity is real.
        // return isCelebrity(possibleCelebrity) ? true : -1;
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



