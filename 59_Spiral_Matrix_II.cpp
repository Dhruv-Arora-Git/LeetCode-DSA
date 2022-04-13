// https://leetcode.com/problems/spiral-matrix-ii/

// https://leetcode.com/problems/spiral-matrix-ii/discuss/1942513/Super-Simple-Code-oror-C%2B%2B-oror-Easy-to-Understand

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int n)
{
    // initialize a 2D vector with all 0s
    vector<vector<int>> ans(n, vector<int>(n, 0));

    // to put elements - 1,2,3...
    int count = 1;

    // boundaries
    int left = 0, right = n;
    int top = 0, bottom = n;

    while (top < bottom && left < right)
    {
        // filling first(top) row
        for (int i = left; i < right; ++i)
            ans[top][i] = count++;

        ++top;

        // filling right column
        for (int i = top; i < bottom; ++i)
            ans[i][right - 1] = count++;

        --right;

        // filling bottom row
        for (int i = right - 1; i >= left; --i)
            ans[bottom - 1][i] = count++;

        --bottom;

        // filling left column
        for (int i = bottom - 1; i >= top; --i)
            ans[i][left] = count++;

        ++left;
    }

    return ans;
}

int main()
{
    int n = 3;

    vector<vector<int>> ans = generateMatrix(n);

    for (vector<int> v : ans)
    {
        for (int i : v)
            cout << i << " ";
        cout << '\n';
    }
    return 0;
}