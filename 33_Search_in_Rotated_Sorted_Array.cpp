// https://leetcode.com/problems/search-in-rotated-sorted-array/

// https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/1702729/C%2B%2B-find-pivot-with-binary-search-or-O(log-n)

#include <iostream>
#include <vector>

using namespace std;
int pivot(vector<int> &nums)
{
    int start = 0;
    int end = nums.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (mid < end and nums[mid] > nums[mid + 1])
            return mid;

        if (mid > start and nums[mid] < nums[mid - 1])
            return mid;

        if (nums[start] >= nums[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }

    return -1;
}

int binarySearch(vector<int> &nums, int target, int start, int end)
{

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            start = mid + 1;
        else if (nums[mid] > target)
            end = mid - 1;
    }
    return -1;
}

int search(vector<int> &nums, int target)
{
    int pivotEle = pivot(nums);

    // if pivot == -1, means array is not rotated, just do normal binary search
    if (pivotEle == -1)
        return binarySearch(nums, target, 0, nums.size() - 1);

    // case 1 : pivot ele == target
    if (nums[pivotEle] == target)
        return pivotEle;

    // case 2 : target > start ele
    if (target >= nums[0])
        return binarySearch(nums, target, 0, pivotEle - 1);
    else
        return binarySearch(nums, target, pivotEle + 1, nums.size() - 1);
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    cout << search(nums, target) << '\n';
    return 0;
}