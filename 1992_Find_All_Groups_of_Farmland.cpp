// https://leetcode.com/problems/find-all-groups-of-farmland/

// https://leetcode.com/problems/find-all-groups-of-farmland/discuss/2433481/Simple-DFS-with-max()-Logic-oror-Comments-Added-C%2B%2B

#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &land, int i, int j, int rows, int cols, int &x, int &y)
{
    // checking bounds
    if (i < 0 || i >= rows || j < 0 || j >= cols || land[i][j] == 0)
        return;

    // as the bottom right corner will have the most +ve coords, just take the max
    x = max(x, i);
    y = max(y, j);

    land[i][j] = 0; // marking visited

    // checking for neighbour coords
    dfs(land, i + 1, j, rows, cols, x, y);
    dfs(land, i, j + 1, rows, cols, x, y);
    dfs(land, i - 1, j, rows, cols, x, y);
    dfs(land, i, j - 1, rows, cols, x, y);
}

vector<vector<int>> findFarmland(vector<vector<int>> &land)
{

    int rows = land.size();
    int cols = land[0].size();

    vector<vector<int>> farmCoords;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (land[i][j] == 1)
            {

                vector<int> coords;

                // initial coords
                coords.push_back(i);
                coords.push_back(j);

                // final coords to find
                int x = i, y = j;

                dfs(land, i, j, rows, cols, x, y);

                // final coords after dfs
                coords.push_back(x);
                coords.push_back(y);

                farmCoords.push_back(coords);
            }
        }
    }

    return farmCoords;
}

int main()
{
    vector<vector<int>> land = {
        {1, 0, 0},
        {0, 1, 1},
        {0, 1, 1},
    };

    vector<vector<int>> farmCoords = findFarmland(land);

    for (auto &farm : farmCoords)
    {
        cout << farm[0] << " " << farm[1] << " " << farm[2] << " " << farm[3] << "\n";
    }

    return 0;
}