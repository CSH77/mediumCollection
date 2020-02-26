#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <string.h>

using namespace std;

class Solution {
public:
    enum RomanNumber
    {
        I=1,
        V=5,
        X=10,
        L=50,
        C=100,
        D=500,
        M=1000
    };

    int romanToInt(string s) {

        int romanNumber[100];
        memset(romanNumber, 0, sizeof(romanNumber));
        romanNumber['I'] = I;
        romanNumber['V'] = V;
        romanNumber['X'] = X;
        romanNumber['L'] = L;
        romanNumber['C'] = C;
        romanNumber['D'] = D;
        romanNumber['M'] = M;

        if(s.size() == 1)
            return romanNumber[s.at(0)];

        int total = 0;
        int current = 0;
        int next = 0;

        for(int i = 0; i < s.size() - 1; i++)
        {
            current = romanNumber[s.at(i)];
            next = romanNumber[s.at(i+1)];

            if(current >= next)
            {
                total = total + current;
                if(i == s.size() - 2 )
                    total = total + next;
            }
            else
            {
                total = total + (next - current);
                i++;
                if(i == s.size() - 2)
                    total = total + romanNumber[s.at(i+1)];
            }
        }
        return total;
    }
};
int main()
{
    string input = "LVIII";
    Solution obj;
    cout << obj.romanToInt(input) << endl; //expect 58

    return 0;
}



