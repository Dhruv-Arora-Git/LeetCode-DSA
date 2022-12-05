// https://leetcode.com/problems/minimum-path-sum/

// https://leetcode.com/problems/minimum-path-sum/discuss/2880796/C%2B%2B-Memoization-DP-oror-Recursion-with-clean-comments

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int dp[201][201];

int rec(vector<vector<int>> &grid, int i, int j)
{
    // pruning statement to check out of bounds
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
        return 1e9;

    // base case, reached at destination
    if (i == grid.size() - 1 && j == grid[0].size() - 1)
        return grid[i][j];

    // cache check
    if (dp[i][j] != -1)
        return dp[i][j];

    // compute and store/memoize
    return dp[i][j] = min(grid[i][j] + rec(grid, i + 1, j),
                          grid[i][j] + rec(grid, i, j + 1));
}

int minPathSum(vector<vector<int>> &grid)
{
    memset(dp, -1, sizeof dp);

    return rec(grid, 0, 0);
}

int main()
{
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};

    cout << minPathSum(grid) << "\n";

    return 0;
}