// https://leetcode.com/problems/two-furthest-houses-with-different-colors/

// https://leetcode.com/problems/two-furthest-houses-with-different-colors/discuss/1846189/very-simple-O(n)-solution-or-C%2B%2B

#include <iostream>
#include <vector>

using namespace std;

int maxDistance(vector<int> &colors)
{
    int res = 0, n = colors.size();

    for (int i = 0; i < n; ++i)
    {

        if (colors[i] != colors[0])
            res = max(res, i);

        if (colors[i] != colors[n - 1])
            res = max(res, n - 1 - i);
    }

    return res;
}

int main()
{
    vector<int> colors = {4, 4, 4, 11, 4, 4, 11, 4, 4, 4, 4, 4};
    cout << maxDistance(colors) << '\n';
    return 0;
}