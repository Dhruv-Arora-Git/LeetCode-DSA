// https://leetcode.com/problems/ugly-number/

// https://leetcode.com/problems/ugly-number/discuss/1861104/simple-C%2B%2B-solution-explained-with-comments

#include <iostream>
using namespace std;

bool isUgly(int n)
{

    if (n == 0)
        return false;
    if (n == 1)
        return true;

    // just checking if its divisible by 2,3 or 5
    // if it is, divide it and check again
    // if it's not, means 2,3 or 5 can't divide it, return false
    while (n != 1)
    {
        if (n % 2 == 0)
            n /= 2;
        else if (n % 3 == 0)
            n /= 3;
        else if (n % 5 == 0)
            n /= 5;
        else
            return false;
    }

    // if we are here it means, everything is fine, and n was divisible only by 2,3 or 5
    return true;
}

int main()
{
    int n = 14;

    cout << isUgly(n) << '\n';

    return 0;
}