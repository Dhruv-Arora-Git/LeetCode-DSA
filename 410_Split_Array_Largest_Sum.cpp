// https://leetcode.com/problems/split-array-largest-sum/

// https://leetcode.com/problems/split-array-largest-sum/discuss/1705209/Binary-Search-or-C%2B%2B-or-Simple-solution
// was asked in google
#include <iostream>
#include <vector>

using namespace std;

bool isValid(vector<int> &nums, int m, int mx)
{
    int index = 1;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (sum > mx)
        {
            index++;
            sum = nums[i];
        }

        if (index > m)
            return false;
    }

    return true;
}

int splitArray(vector<int> &nums, int m)
{
    int max = -1, sum = 0;

    for (int i : nums)
    {
        if (i > max)
            max = i;

        sum += i;
    }

    int start = max;
    int end = sum;
    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isValid(nums, m, mid))
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
    vector<int> nums = {7, 2, 5, 10, 8};
    int m = 2;

    cout << splitArray(nums, m) << '\n';
    return 0;
}