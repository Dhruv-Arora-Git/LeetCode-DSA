// https://leetcode.com/problems/single-element-in-a-sorted-array/

// https://leetcode.com/problems/single-element-in-a-sorted-array/discuss/3213478/C%2B%2B-Even-Odd-Condition-or-Binary-Search

#include <iostream>
#include <vector>

using namespace std;

int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {

        int mid = low + (high - low) / 2;

        if (low == high)
            return nums[low];

        if (mid == 0 || mid == n - 1)
        {
            return nums[mid];
        }

        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
            return nums[mid];

        // even
        if (mid % 2 == 0)
        {
            if (nums[mid] == nums[mid - 1])
                high = mid - 1;
            else
                low = mid + 1;
        }
        // odd
        else
        {
            if (nums[mid] == nums[mid - 1])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};

    cout << singleNonDuplicate(nums) << "\n";
    return 0;
}