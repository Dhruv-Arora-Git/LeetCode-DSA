// https://leetcode.com/problems/search-in-rotated-sorted-array/

// iterative solution
// https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/1702729/C%2B%2B-find-pivot-with-binary-search-or-O(log-n)

// recursive solution
// https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/1746787/Recursion-Solution-or-C%2B%2B-or-with-comments-%3A)

#include <iostream>
#include <vector>

using namespace std;

// iterative solution
// ===========================================================
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
// =========================================================

// Recursive Solution
// ****************************************************
int helper(vector<int> &arr, int target, int start, int end)
{
    if (start > end)
        return -1;

    int mid = start + (end - start) / 2;

    if (arr[mid] == target)
        return mid;

    if (arr[start] <= arr[mid])
    {
        // left sorted part
        if (target >= arr[start] && target <= arr[mid])
        {
            // if target lies in this sorted range, search in this only, discard right part, by end = mid - 1
            end = mid - 1;
        }
        else
        {
            // means, it does not lies here, so discard this part, by, start = mid + 1
            start = mid + 1;
        }
    }
    else
    {
        // arr[start] > arr[mid]
        if (target >= arr[mid] && target <= arr[end])
        {
            // target is in this range, so discard left part (start = mid + 1), now search in this
            start = mid + 1;
        }
        else
        {
            // else, it's not in that range, so search in left part now
            end = mid - 1;
        }
    }
    // recursive call
    return helper(arr, target, start, end);
}

int search2(vector<int> &nums, int target)
{
    // return what we are getting from helper function
    return helper(nums, target, 0, nums.size() - 1);
    // we made helper, so that, we can pass start and end after computing, in another recursion calls
}
// **************************************************

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    cout << search2(nums, target) << '\n';
    return 0;
}