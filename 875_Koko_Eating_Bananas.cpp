// https://leetcode.com/problems/koko-eating-bananas/

// https://leetcode.com/problems/koko-eating-bananas/discuss/1726591/C%2B%2B-or-Binary-Search-or-Easy-and-Simple

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

bool isValid(vector<int> &piles, int h, int mx)
{
    int hours = 0;

    for (int i = 0; i < piles.size(); i++)
    {
        hours += ceil(1.0 * piles[i] / mx);
    }

    return hours <= h;
}

int minEatingSpeed(vector<int> &piles, int h)
{
    int mx = 0;
    for (int i = 0; i < piles.size(); i++)
        mx = max(mx, piles[i]);

    if (piles.size() == h)
        return mx;

    int start = 1;
    int end = mx;
    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isValid(piles, h, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{

    vector<int> piles = {3, 6, 7, 1000000000};
    int h = 5;

    cout << minEatingSpeed(piles, h) << '\n';

    return 0;
}