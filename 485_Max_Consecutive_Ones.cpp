// https://leetcode.com/problems/max-consecutive-ones/

// https://leetcode.com/problems/max-consecutive-ones/discuss/1650679/Easy-C%2B%2B-Solution-O(n)-time

#include <iostream>
#include <vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int max_count = 0;
    int count = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            max_count = max(count, max_count);
            count = 0;
        }
        else
        {
            count++;
        }
    }

    return max(max_count, count);
}

int main()
{
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    cout << findMaxConsecutiveOnes(nums) << '\n';

    return 0;
}