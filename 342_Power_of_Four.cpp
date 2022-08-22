// https://leetcode.com/problems/power-of-four/

// https://leetcode.com/problems/power-of-four/discuss/2462369/C%2B%2B-3-lines-or-log-or-Simple-maths-Explained

#include <iostream>
#include <cmath>

using namespace std;
bool isPowerOfFour(int n)
{
    if (n == 0)
        return false;

    double ans = log(n) / log(4);

    return ceil(ans) == floor(ans); // just checking if it's a whole number without any decimal point
}
int main()
{
    int n = 16;
    cout << boolalpha << isPowerOfFour(n) << "\n";
    return 0;
}