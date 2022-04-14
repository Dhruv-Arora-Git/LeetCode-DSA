// https://leetcode.com/problems/trapping-rain-water/

// https://leetcode.com/problems/trapping-rain-water/discuss/1946848/C%2B%2B-Precomputation-Approach-Easy-and-Simple-%3A)

#include <iostream>
#include <vector>

using namespace std;

int trap(vector<int> &height)
{
    int n = height.size();

    // finding max left to current element
    int mxLeft[n];

    int mx_left = height[0];

    for (int i = 0; i < n; ++i)
    {
        mx_left = max(mx_left, height[i]);
        mxLeft[i] = mx_left;
    }

    // finding max right to current element
    int mxRight[n];

    int mx_right = height[n - 1];

    for (int i = n - 1; i >= 0; --i)
    {
        mx_right = max(mx_right, height[i]);
        mxRight[i] = mx_right;
        ;
    }

    int water[n];

    for (int i = 0; i < n; ++i)
    {

        // we chose min of both as it will bound the amount of water
        // ex 3, 0, 4 => max water height will be 3, not 4 (it will overflow)
        int mx_height = min(mxRight[i], mxLeft[i]);

        // height of water = max height it can go - height of current building
        // ex - 3, 0, 4 => at i = 1, element = 0
        // min(3,4) - 0 => 3 - 0 => 3
        water[i] = (mx_height - height[i]);
    }

    int total_water = 0;

    // summing up all the water
    for (int i : water)
        total_water += i;

    return total_water;
}

int main()
{
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    cout << trap(height) << '\n';

    return 0;
}