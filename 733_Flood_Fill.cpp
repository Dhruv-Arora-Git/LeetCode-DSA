// https://leetcode.com/problems/flood-fill/

// https://leetcode.com/problems/flood-fill/discuss/2155890/DFS-oror-No-visited-!-oror-Comments-Added

#include <iostream>
#include <vector>

using namespace std;

void changeColor(vector<vector<int>> &image, int i, int j, int n, int m, int currColor, int newColor)
{
    // check for bounds
    if ((i < 0) || (i >= n) || (j < 0) || (j >= m) || image[i][j] != currColor)
        return;

    // changing curent grid (i, j) to new color
    image[i][j] = newColor;

    changeColor(image, i + 1, j, n, m, currColor, newColor); // up
    changeColor(image, i - 1, j, n, m, currColor, newColor); // down
    changeColor(image, i, j + 1, n, m, currColor, newColor); // right
    changeColor(image, i, j - 1, n, m, currColor, newColor); // left
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int n = image.size();
    int m = image[0].size();

    int currColor = image[sr][sc];

    if (currColor == newColor) // no need to repaint
        return image;

    changeColor(image, sr, sc, n, m, currColor, newColor);

    return image;
}

int main()
{
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1},
    };
    int sr = 1, sc = 1;
    int color = 2;

    floodFill(image, sr, sc, color);

    for (vector<int> &v : image)
    {
        for (int &i : v)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}