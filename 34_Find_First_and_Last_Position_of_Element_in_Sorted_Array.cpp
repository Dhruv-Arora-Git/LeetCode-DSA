// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/discuss/2330311/Single-Binary-Search-Function-or-Clean-Code-C%2B%2B

#include <iostream>
#include <vector>

using namespace std;

int occurance(vector<int> &nums, int target, bool firstOcc)
{
    int ans = -1;

    int start = 0, end = nums.size() - 1;

    while (start <= end)
    {

        int mid = start + (end - start) / 2;

        if (nums[mid] == target)
        {
            ans = mid;

            // if we want first occurance
            if (firstOcc)
                end = mid - 1;
            else // last occurance
                start = mid + 1;
        }

        else if (nums[mid] < target)
            start = mid + 1;

        else if (nums[mid] > target)
            end = mid - 1;
    }

    return ans;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> ans(2, -1);

    ans[0] = occurance(nums, target, true);  // first occurance
    ans[1] = occurance(nums, target, false); // last occurance

    return ans;
}

int main()
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> ans = searchRange(nums, target);

    for (int &i : ans)
        cout << i << " ";
    cout << "\n";

    return 0;
}