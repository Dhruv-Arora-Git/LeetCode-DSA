// https://leetcode.com/problems/missing-number/

// https://leetcode.com/problems/missing-number/discuss/1687365/Simple-C%2B%2B-Solution

// asked by amazon
#include <iostream>
#include <vector>

using namespace std;

// intution : array contains **Range from 1 to N only**
int missingNumber(vector<int> &nums)
{
    int n = nums.size();

    long int sum = n * (n + 1) / 2;

    long int total = 0;
    for (int i : nums)
    {
        total += i;
    }

    return sum - total;
}

int main()
{
    vector<int> nums = {1, 2};
    cout << missingNumber(nums) << '\n';
    return 0;
}