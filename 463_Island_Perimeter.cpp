// https://leetcode.com/problems/island-perimeter/

// https://leetcode.com/problems/island-perimeter/discuss/2406149/C%2B%2B-Clean-Code-or-Explained-with-Comments

#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j, int row, int col, int &ans)
{

    // checking bounds
    if (i >= 0 && i < row && j >= 0 && j < col && visited[i][j] == false && grid[i][j] == 1)
    {
        visited[i][j] = true; // marking visited

        // checking for boundaries and water
        if (i + 1 == row || grid[i + 1][j] == 0)
            ++ans;
        if (i - 1 < 0 || grid[i - 1][j] == 0)
            ++ans;
        if (j + 1 == col || grid[i][j + 1] == 0)
            ++ans;
        if (j - 1 < 0 || grid[i][j - 1] == 0)
            ++ans;

        // checking the 4 sides
        dfs(grid, visited, i + 1, j, row, col, ans);
        dfs(grid, visited, i - 1, j, row, col, ans);
        dfs(grid, visited, i, j + 1, row, col, ans);
        dfs(grid, visited, i, j - 1, row, col, ans);
    }
}

int islandPerimeter(vector<vector<int>> &grid)
{
    int row = grid.size();
    int col = grid[0].size();

    vector<vector<bool>> visited(row, vector<bool>(col, false));

    int perimeter = 0;

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            if (grid[i][j] == 1)
            {
                dfs(grid, visited, i, j, row, col, perimeter);
                break; // as there is only 1 island, it will be covered in single DFS only
            }
        }
    }

    return perimeter;
}

int main()
{
    vector<vector<int>> grid = {
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0},
    };

    cout << islandPerimeter(grid) << "\n";
    return 0;
}