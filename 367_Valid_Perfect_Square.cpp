#include <iostream>
using namespace std;

bool isPerfectSquare(int num)
{
    if (num == 1)
        return true;

    int start = 0;
    int end = num - 1;
    long long mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (mid * mid == num)
            return true;
        else if (mid * mid > num)
        {
            end = mid - 1;
        }
        else if (mid * mid < num)
        {
            start = mid + 1;
        }

        mid = start + (end - start) / 2;
    }
    return false;
}

int main()
{
    int num = 16;
    cout << isPerfectSquare(num) << '\n';
    return 0;
}