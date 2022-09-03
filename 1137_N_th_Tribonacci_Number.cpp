// https://leetcode.com/problems/n-th-tribonacci-number/

// https://leetcode.com/problems/n-th-tribonacci-number/discuss/2524626/C%2B%2B-Just-Simple-Memoization-oror-0-ms-for-DP-Beginners

#include <iostream>
#include <vector>

using namespace std;

vector<int> dp = vector<int>(38, -1);

int tribonacci(int n)
{
    if (n == 0)
        return dp[n] = 0;
    if (n == 1 || n == 2)
        return dp[n] = 1;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = tribonacci(n - 3) + tribonacci(n - 2) + tribonacci(n - 1);
}

int main()
{
    int n = 25; // output: 1389537

    cout << tribonacci(n) << "\n";

    return 0;
}