// https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/

// https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/discuss/1836802/C%2B%2B-Binary-Search-approach-or-faster-than-100

#include <iostream>
#include <vector>

using namespace std;

bool isValid(vector<int> &nums, int k)
{

    int sum = k;

    for (int i = 0; i < nums.size(); ++i)
    {
        if (sum + nums[i] < 1)
            return false;

        sum += nums[i];
    }

    return true;
}

int minStartValue(vector<int> &nums)
{

    int start = 1, end = 100001;

    int ans = 0;

    while (start <= end)
    {

        int mid = start + (end - start) / 2;

        if (isValid(nums, mid))
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
    vector<int> nums = {-3, 2, -3, 4, 2};

    cout << minStartValue(nums) << '\n';
    return 0;
}