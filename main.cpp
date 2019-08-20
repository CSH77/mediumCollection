#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {

        bool aNegative = (numerator < 0) != (denominator < 0);
        long long aNum = numerator, aDen = denominator;

        aNum = abs(aNum);
        aDen = abs(aDen);

        long long aDigit = aNum / aDen;
        string aResult = to_string(aDigit);

        long long aRemainder = (aNum % aDen) * 10;

        if (aNegative && (aDigit != 0 || aRemainder != 0))
        {
            aResult = string("-") + aResult;
        }

        if (aRemainder != 0)
        {

            aResult.append(".");
            unordered_map<int, int> aRepeatMap(64);

            while (aRemainder != 0)
            {
                if (aRepeatMap[aRemainder] != 0)
                {
                    aResult.insert(aRepeatMap[aRemainder], "(");
                    aResult.append(")");
                    break;
                }
                else
                {
                    aRepeatMap[aRemainder] = aResult.size();
                    aResult.append(to_string(aRemainder / aDen));
                    aRemainder = (aRemainder % aDen) * 10;
                }
            }
        }

        return aResult;
    }
};


int main()
{
    Solution obj;
    cout << obj.fractionToDecimal(4,3);

    return 0;
}



