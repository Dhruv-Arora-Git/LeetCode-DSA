// https://leetcode.com/problems/count-sub-islands/

// https://leetcode.com/problems/count-sub-islands/discuss/2433698/with-and-without-Visited-Array-oror-brute-to-optimal-C%2B%2B

#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int i, int j, int rows, int cols, bool &flag)
{
    // checking bounds
    if (i < 0 || i >= rows || j < 0 || j >= cols || grid2[i][j] == 0)
        return;

    if (grid1[i][j] == 0 && grid2[i][j] == 1)
    { // means the grid2's area does not lie in grid1's
        flag = false;
        return;
    }

    grid2[i][j] = 0; // marking visited

    // checking for neighbour cells
    dfs(grid1, grid2, i + 1, j, rows, cols, flag);
    dfs(grid1, grid2, i - 1, j, rows, cols, flag);
    dfs(grid1, grid2, i, j + 1, rows, cols, flag);
    dfs(grid1, grid2, i, j - 1, rows, cols, flag);
}

int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
{
    int rows = grid1.size();
    int cols = grid1[0].size();

    int count = 0;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (grid2[i][j] == 1)
            {
                bool flag = true;

                dfs(grid1, grid2, i, j, rows, cols, flag);

                if (flag) // means after dfs check, grid2's region is inside grid1's
                    ++count;
            }
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> grid1 = {
        {1, 1, 1, 0, 0},
        {0, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1},
    };
    vector<vector<int>> grid2 = {
        {1, 1, 1, 0, 0},
        {0, 0, 1, 1, 1},
        {0, 1, 0, 0, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 1, 0},
    };

    cout << countSubIslands(grid1, grid2) << "\n";
    return 0;
}