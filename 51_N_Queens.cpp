// https://leetcode.com/problems/n-queens/

// https://leetcode.com/problems/n-queens/discuss/2672780/C%2B%2B-Commented-Nicely-oror-different-approach-Storing-prev-Queens-positions

#include <iostream>
#include <vector>

using namespace std;

vector<int> queens = vector<int>(9, -1); // store the position of queen at a particular level/row (9 is max in the question)

vector<vector<string>> ans;

// checking valid queen placement
bool valid(int row, int col)
{

    // from 0th row till this one
    for (int i = 0; i < row; ++i)
    {

        int pCol = queens[i]; // position of queen at previous ith row

        if (pCol == col || abs(pCol - col) == abs(i - row))
            return false;
    }

    return true;
}

void rec(int row, int &n)
{
    if (row == n)
    { // means we have placed the queens succesfully

        // creating the final board
        vector<string> v;

        for (int i = 0; i < n; ++i)
        {
            string s = "";
            int pos = queens[i]; // position of ith queen
            for (int j = 0; j < n; ++j)
            {
                (j == pos) ? s.push_back('Q') : // queen placed
                    s.push_back('.');           // no queen placed
            }
            v.push_back(s);
        }

        ans.push_back(v);
        return;
    }

    // choices
    for (int col = 0; col < n; ++col)
    {
        if (valid(row, col))
        {
            queens[row] = col; // placing the queen

            rec(row + 1, n); // checking next row

            queens[row] = -1; // revert placing the queen / backtracking
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    rec(0, n); // calling from row 0
    return ans;
}

int main()
{

    int n;
    cin >> n;
    vector<vector<string>> ans = solveNQueens(n);

    for (vector<string> &v : ans)
    {
        cout << "[\n";
        for (string &s : v)
            cout << s << "\n";

        cout << "],\n";
    }
    return 0;
}