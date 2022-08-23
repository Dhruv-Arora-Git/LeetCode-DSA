// https://leetcode.com/problems/pacific-atlantic-water-flow/

// https://leetcode.com/problems/pacific-atlantic-water-flow/discuss/2468157/Think-the-other-way!-Ocean-to-Land-DFS-C%2B%2B-oror-Explaind

#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &land, vector<vector<bool>> &oceanToLand, int i, int j, int rows, int cols)
{
    if (i < 0 || i >= rows || j < 0 || j >= cols || oceanToLand[i][j] == true)
        return;

    oceanToLand[i][j] = true; // marking visited, means ocean water can come to that land

    // just checking the neighbouring cells
    if (i + 1 < rows && land[i + 1][j] >= land[i][j])
        dfs(land, oceanToLand, i + 1, j, rows, cols);

    if (i - 1 >= 0 && land[i - 1][j] >= land[i][j])
        dfs(land, oceanToLand, i - 1, j, rows, cols);

    if (j + 1 < cols && land[i][j + 1] >= land[i][j])
        dfs(land, oceanToLand, i, j + 1, rows, cols);

    if (j - 1 >= 0 && land[i][j - 1] >= land[i][j])
        dfs(land, oceanToLand, i, j - 1, rows, cols);
}

vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
{

    vector<vector<int>> ans;

    int rows = heights.size();
    int cols = heights[0].size();

    vector<vector<bool>> pacificToLand(rows, vector<bool>(cols, false));
    vector<vector<bool>> atlanticToLand(rows, vector<bool>(cols, false));

    // column 0 is pacific ocean's boundary and last column (cols - 1) is atlantic's
    for (int i = 0; i < rows; ++i)
    {
        dfs(heights, pacificToLand, i, 0, rows, cols);
        dfs(heights, atlanticToLand, i, cols - 1, rows, cols);
    }

    // row 0 is pacific ocean's boundary and last row (rows - 1) is atlantic's
    for (int i = 0; i < cols; ++i)
    {
        dfs(heights, pacificToLand, 0, i, rows, cols);
        dfs(heights, atlanticToLand, rows - 1, i, rows, cols);
    }

    // if from *both* oceans, we can reach to a particular cell of land, then vice-versa is also true
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (pacificToLand[i][j] && atlanticToLand[i][j])
            {
                ans.push_back({i, j});
            }
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> heights = {
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4},
    };

    vector<vector<int>> ans = pacificAtlantic(heights);

    for (auto &v : ans)
        cout << v[0] << " " << v[1] << ", ";

    cout << "\n";

    return 0;
}