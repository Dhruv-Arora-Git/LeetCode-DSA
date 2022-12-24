// https://leetcode.com/problems/domino-and-tromino-tiling/

// https://leetcode.com/problems/domino-and-tromino-tiling/solutions/2945092/c-approach-explained-with-picture-0-ms-recurive-dp-code/?orderBy=most_votes

#include <iostream>
#include <cstring>

using namespace std;

const int mod = 1e9 + 7;
int dp[2][1001];

long rec(int a, bool gap)
{
    if (a < 0)
        return 0;

    if (a == 0)
        return (gap == 0) ? 1 : 0;

    if (dp[gap][a] != -1)
        return dp[gap][a];

    if (gap == 0)
        return dp[gap][a] = (rec(a - 1, 0) + rec(a - 2, 0) + 2 * rec(a - 2, 1)) % mod;

    return dp[gap][a] = (rec(a - 1, 1) + rec(a - 1, 0)) % mod;
}

int numTilings(int a)
{
    memset(dp, -1, sizeof dp);
    return rec(a, 0);
}

int main()
{
    cout << numTilings(3) << "\n";
    return 0;
}