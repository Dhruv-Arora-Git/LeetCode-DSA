// https://leetcode.com/problems/running-sum-of-1d-array/

// https://leetcode.com/problems/running-sum-of-1d-array/discuss/1660203/C%2B%2B-simple-for-loop-or-easy-to-understand-solution

#include <iostream>
#include <vector>

using namespace std;

vector<int> runningSum(vector<int> &nums)
{
    vector<int> sum_arr;

    int current_sum = 0;

    for (int &i : nums)
    {
        current_sum += i;
        sum_arr.push_back(current_sum);
    }

    return sum_arr;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    vector<int> ans = runningSum(nums);

    for (int &i : ans)
        cout << i << " ";

    cout << '\n';

    return 0;
}