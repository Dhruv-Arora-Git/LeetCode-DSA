#include <iostream>
#include <limits.h>
using namespace std;

int reverse(int x)
{
    int reverse = 0;

    while (x != 0)
    {
        int digit = x % 10;
        if (reverse > INT_MAX / 10 || reverse < INT_MIN / 10)
        {
            return 0;
        }
        reverse = (reverse * 10) + digit;
        x /= 10;
    }

    return reverse;
}

int main()
{
    int x = -123;
    cout << reverse(x) << '\n';
    return 0;
}