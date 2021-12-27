// https://leetcode.com/problems/sqrtx/

// https://leetcode.com/problems/sqrtx/discuss/1650606/Easy-oror-C%2B%2B-oror-Binary-Search-Solution-oror-O(log-n)-tine

#include <iostream>
using namespace std;

int mySqrt(int x)
{
    if (x <= 1)
        return x;

    int low = 0;
    int high = x - 1;
    long long mid = high + (low - high) / 2;

    int ans = -1;
    while (low <= high)
    {
        if (mid * mid == x)
            return mid;
        else if (mid * mid < x)
        {
            ans = mid;
            low = mid + 1;
        }
        else if (mid * mid > x)
        {
            high = mid - 1;
        }

        mid = high + (low - high) / 2;
    }

    return ans;
}

int main()
{
    int x = 8;
    cout << mySqrt(x) << '\n';
    return 0;
}