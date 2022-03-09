#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    int start = 0, end = nums.size() - 1;

    int ans = nums.size();

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] >= target)
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
    vector<int> nums = {1, 3, 5, 6};
    int tagret = 7;

    cout << searchInsert(nums, tagret) << '\n';

    return 0;
}