// https://leetcode.com/problems/pascals-triangle/

// https://leetcode.com/problems/pascals-triangle/discuss/3346150/C%2B%2BJava-Super-Clean-and-Understandable-Code

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> list;

    for (int i = 0; i < numRows; ++i)
    {
        vector<int> arr;
        for (int j = 0; j < i + 1; ++j)
        {
            if (j == 0 || j == i)
            { // both ends
                arr.push_back(1);
            }
            else
            { // middle
                int upperLeft = list[i - 1][j - 1];
                int upperRight = list[i - 1][j];

                arr.push_back(upperLeft + upperRight);
            }
        }
        list.push_back(arr);
    }

    return list;
}

int main()
{

    int numRows = 5;
    vector<vector<int>> list = generate(numRows);

    for (vector<int> &arr : list)
    {
        for (int &i : arr)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}