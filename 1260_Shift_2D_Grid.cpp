#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
{

    while (k--)
    {
        int row = grid.size();
        int col = grid[0].size();

        int last = grid[row - 1][col - 1];

        queue<int> que;

        for (vector<int> &arr : grid)
        {
            int n = arr.size();
            que.push(arr[n - 1]);
            for (int i = n - 1; i > 0; --i)
            {
                arr[i] = arr[i - 1];
            }
        }

        //         cout << que.front() << " ";

        for (int i = 1; i < row; ++i)
        {
            grid[i][0] = que.front();
            que.pop();
        }

        grid[0][0] = que.front();
        que.pop();
    }

    // while(!que.empty()) {
    //     cout << que.front() << " ";
    //     que.pop();
    // }

    return grid;
}

int main()
{

    return 0;
}