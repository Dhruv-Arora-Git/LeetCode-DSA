// https://leetcode.com/problems/shortest-path-in-binary-matrix/

// https://leetcode.com/problems/shortest-path-in-binary-matrix/discuss/2401703/C%2B%2B-BFS-oror-Readable-Code-oror-Explained-with-Comments

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    int row = grid.size();
    int col = grid[0].size();

    if (grid[0][0] == 1 || grid[row - 1][col - 1] == 1)
        return -1;

    if (row == 1 && col == 1)
        return (grid[row - 1][col - 1]) == 0 ? 1 : -1;

    queue<int> q;

    q.push(0 * col + 0); // formula : rowNo * length of column + colNo

    int level = 1;

    // up, down, left, right, and all diagonals
    vector<vector<int>> dirs = {
        {1, 1},
        {-1, -1},
        {-1, 1},
        {1, -1},
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1},
    };

    while (!q.empty())
    {
        int size = q.size();

        while (size--)
        {
            int node = q.front();
            q.pop();
            int nodeX = node / col;
            int nodeY = node % col;

            for (int k = 0; k < dirs.size(); ++k)
            {
                int nextX = nodeX + dirs[k][0];
                int nextY = nodeY + dirs[k][1];
                // checking bounds
                if (nextX >= 0 && nextX < row && nextY >= 0 && nextY < col)
                {
                    if (grid[nextX][nextY] == 0)
                    {
                        grid[nextX][nextY] = 1; // marking visited
                        q.push(nextX * col + nextY);

                        if (nextX == row - 1 && nextY == col - 1) // reached destination
                            return 1 + level;
                    }
                }
            }
        }
        ++level;
    }

    if (grid[row - 1][col - 1] == 0) // if destination is unvistied after whole BFS
        return -1;

    return level;
}

int main()
{
    // O/P : -1
    // vector<vector<int>> grid = {{0, 0, 0}, {1, 1, 0}, {1, 1, 1}};

    // O/P: 4
    vector<vector<int>> grid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};

    cout << shortestPathBinaryMatrix(grid) << "\n";
    return 0;
}