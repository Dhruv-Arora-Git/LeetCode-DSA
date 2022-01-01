// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/discuss/1650720/C%2B%2B-easy-linear-solution-or-fast-O(n)-or-simple

#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int> &nums)
{
    int count = 0;
    int n = nums.size();

    for (int i = 1; i < n; i++)
    {
        if (nums[i - 1] > nums[i])
            count++;
    }
    if (nums[n - 1] > nums[0])
        count++;

    return count <= 1;
}

int main()
{
    vector<int> nums = {3, 4, 5, 1, 2};
    cout << check(nums) << '\n';

    return 0;
}