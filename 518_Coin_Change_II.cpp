// https://leetcode.com/problems/coin-change-ii/

// https://leetcode.com/problems/coin-change-ii/discuss/3229383/C%2B%2B-Naive-Unbounded-KnapSack-DP-Code-for-beginners-%3A)

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp;

int rec(vector<int> &coins, int i, int amt)
{
    if (i == coins.size() || amt < 0)
        return 0;

    if (amt == 0)
        return 1;

    if (dp[i][amt] != -1)
        return dp[i][amt];

    return dp[i][amt] = rec(coins, i + 1, amt) + rec(coins, i, amt - coins[i]);
}

int change(int amount, vector<int> &coins)
{
    dp = vector(coins.size(), vector<int>(amount + 1, -1));

    return rec(coins, 0, amount);
}

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 5;

    cout << change(amount, coins) << "\n";
    return 0;
}