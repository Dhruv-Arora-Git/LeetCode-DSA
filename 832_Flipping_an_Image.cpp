// https://leetcode.com/problems/flipping-an-image/

// https://leetcode.com/problems/flipping-an-image/discuss/1691657/C%2B%2B-or-no-extra-space-or-100-fast-or-With-Comments-%3A)

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> flipAndInvertImage(vector<vector<int>> &image)
{

    for (int i = 0; i < image.size(); i++)
    {
        for (int j = 0; j < (image[i].size() + 1) / 2; j++)
        {
            // reversing and inverting
            // 0 ^ 1 = 1, 1 ^ 1 = 0
            int temp = image[i][j] ^ 1;
            image[i][j] = image[i][image[i].size() - j - 1] ^ 1;
            image[i][image[i].size() - j - 1] = temp;
            // simple 2 pointer approch to reverse an array/vector
        }
    }
    return image;
}

int main()
{
    vector<vector<int>> image = {{1, 1, 0, 0},
                                 {1, 0, 0, 1},
                                 {0, 1, 1, 1},
                                 {1, 0, 1, 0}};

    vector<vector<int>> flipped = flipAndInvertImage(image);

    // 1 1 0 0
    // 0 1 1 0
    // 0 0 0 1
    // 1 0 1 0
    for (vector<int> i : flipped)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << '\n';
    }
    return 0;
}