// https://leetcode.com/problems/edit-distance/

// https://leetcode.com/problems/edit-distance/discuss/3232868/C%2B%2B-Memoization-DP-oror-Explained-with-Comments

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> memo;

int dp(string &word1, string &word2, int i, int j)
{
    // If either of the strings is empty, return the length of the other string
    if (i == 0)
        return j;
    if (j == 0)
        return i;

    // If the result is already calculated, return it from the memoization table
    if (memo[i][j] != -1)
        return memo[i][j];

    int ans;

    if (word1[i - 1] == word2[j - 1])
    {
        // If the characters at i-1 and j-1 match, no operation is required
        ans = dp(word1, word2, i - 1, j - 1);
    }
    else
    {
        // Find the minimum of the three operations
        ans = 1 + min({dp(word1, word2, i, j - 1),       // insert
                       dp(word1, word2, i - 1, j),       // delete
                       dp(word1, word2, i - 1, j - 1)}); // replace
    }

    // Store the result in the memoization table and return
    return memo[i][j] = ans;
}

int minDistance(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();

    // Initialize the memoization table with -1
    memo = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));

    return dp(word1, word2, n, m);
}

int main()
{
    string word1 = "horse";
    string word2 = "ros";

    cout << "Minimum number of operations to convert " << word1 << " to " << word2 << " is " << minDistance(word1, word2) << "\n";
    return 0;
}