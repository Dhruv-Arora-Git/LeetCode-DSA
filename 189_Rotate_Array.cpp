// https://leetcode.com/problems/rotate-array/

// https://leetcode.com/problems/rotate-array/discuss/1731257/Simple-Reverse-func-or-C%2B%2B-or-O(1)-space

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate(vector<int> &nums, int k)
{
    if (nums.size() < 2 || nums.size() == k)
        return;
    k = k % nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin() + k, nums.end());
    reverse(nums.begin(), nums.begin() + k);
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    rotate(nums, k);

    for (int i : nums)
        cout << i << " ";

    cout << '\n';
    return 0;
}