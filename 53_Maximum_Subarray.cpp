// https://leetcode.com/problems/maximum-subarray/

// https://leetcode.com/problems/maximum-subarray/discuss/1902838/Classic-kadane's-Algo-Solution-C%2B%2B

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxSubArray(vector<int> &nums)
{

    int curr_sum = 0;
    int max_sum = INT_MIN;

    for (int i = 0; i < nums.size(); ++i)
    {
        if (curr_sum + nums[i] >= nums[i])
        {
            curr_sum += nums[i];
        }
        else
        {
            curr_sum = nums[i];
        }

        if (curr_sum > max_sum)
        {
            max_sum = curr_sum;
        }
    }

    return max_sum;
}

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << maxSubArray(nums) << "\n";
    return 0;
}