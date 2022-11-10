// https://leetcode.com/problems/target-sum/

// https://leetcode.com/problems/target-sum/discuss/2799317/C%2B%2B-DP-oror-Memoize-negative-indexes-with-an-offset

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int dp[21][2001];
int ways(vector<int> &arr, int target, int i, int sum)
{
    if (i == arr.size())
        return (target == sum) ? 1 : 0;

    if (sum < 0) // -ve index offset as, 0 <= sum(nums[i]) <= 1000, so, at max -1 + 2001 = 2000
        if (dp[i][sum + 2001] != -1)
            return dp[i][sum + 2001];

        else if (sum >= 0)
            if (dp[i][sum] != -1)
                return dp[i][sum];

    int addIt = ways(arr, target, i + 1, sum + arr[i]);
    int subtractIt = ways(arr, target, i + 1, sum - arr[i]);

    return (sum < 0) ? dp[i][sum + 2001] = addIt + subtractIt : dp[i][sum] = addIt + subtractIt;
}

int findTargetSumWays(vector<int> &arr, int target)
{
    memset(dp, -1, sizeof(dp));
    return ways(arr, target, 0, 0);
}

int main()
{
    vector<int> arr = {1, 1, 1, 1, 1};
    int target = 3;

    cout << findTargetSumWays(arr, target) << "\n";

    return 0;
}