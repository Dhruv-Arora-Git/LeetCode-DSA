// https://leetcode.com/problems/transpose-matrix/

// https://leetcode.com/problems/transpose-matrix/discuss/2102244/C%2B%2B-Clean-Code-%2B-Follow-up%3A-Square-Matrix

#include <iostream>
#include <vector>

using namespace std;

// T.C. O(n^2), S.C. O(n^2) [not inplace]
vector<vector<int>> transpose(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();

    // n x m matrix for transpose
    vector<vector<int>> trans(n, vector<int>(m, 0));

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            trans[j][i] = matrix[i][j];

    return trans;
}

// Follow up: Square Matrix

// T.C. O(n^2), S.C. O(1) [inplace]
vector<vector<int>> transposeSquare(vector<vector<int>> &matrix)
{
    // for square matrix
    int m = matrix.size();
    int n = matrix[0].size();

    // just swap the UPPER Half with LOWER Half (inplace)
    for (int i = 0; i < m; ++i)
        for (int j = i + 1; j < n; ++j)
            swap(matrix[i][j], matrix[j][i]);

    return matrix;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12},
    };

    vector<vector<int>> ans = transpose(matrix);
    cout << "1. Non-square Matrix\n";
    for (int i = 0; i < ans.size(); ++i)
    {
        for (int j = 0; j < ans[0].size(); ++j)
            cout << ans[i][j] << " ";
        cout << "\n";
    }

    cout << "\n2. Square Matrix\n";

    // for square matrix
    vector<vector<int>> matrix2 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
    };

    vector<vector<int>> ans2 = transposeSquare(matrix2);

    for (int i = 0; i < ans2.size(); ++i)
    {
        for (int j = 0; j < ans2[0].size(); ++j)
            cout << ans2[i][j] << " ";
        cout << "\n";
    }

    return 0;
}