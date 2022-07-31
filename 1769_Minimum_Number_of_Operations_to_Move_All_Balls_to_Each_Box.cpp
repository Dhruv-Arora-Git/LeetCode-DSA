// https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/

// https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/discuss/2359951/C%2B%2B-Explained-or-L-to-R-and-R-to-L-or-O(n)-time

#include <iostream>
#include <vector>

using namespace std;

vector<int> minOperations(string boxes)
{
    int n = boxes.size();

    vector<int> ans(n, 0);

    int balls = 0, operations = 0;

    // left to right
    for (int i = 0; i < n; ++i)
    {
        ans[i] = operations;

        if (boxes[i] == '1')
            ++balls;

        operations += balls;
    }

    // resetting balls and operations
    balls = 0, operations = 0;

    // right to left
    for (int i = n - 1; i >= 0; --i)
    {
        ans[i] += operations;

        if (boxes[i] == '1')
            ++balls;

        operations += balls;
    }

    return ans;
}

int main()
{
    string boxes = "001011";

    vector<int> ans = minOperations(boxes);

    for (int &i : ans)
        cout << i << " ";

    cout << "\n";

    return 0;
}