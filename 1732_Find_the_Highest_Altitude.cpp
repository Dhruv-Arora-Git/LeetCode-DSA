// https://leetcode.com/problems/find-the-highest-altitude/

// https://leetcode.com/problems/find-the-highest-altitude/discuss/1691614/Simple-C%2B%2B-Solution-or-Easy-to-understand

#include <iostream>
#include <vector>

using namespace std;

int largestAltitude(vector<int> &gain)
{
    int altitude = 0;
    int max = 0;

    int n = gain.size();
    for (int i = 0; i < n; i++)
    {
        if (altitude + gain[i] > max)
            max = altitude + gain[i];

        altitude += gain[i];
    }

    return max;
}

int main()
{
    vector<int> gain = {-4, -3, -2, -1, 4, 3, 2};
    int maxAltitude = largestAltitude(gain);
    // 0
    cout << maxAltitude << '\n';

    return 0;
}