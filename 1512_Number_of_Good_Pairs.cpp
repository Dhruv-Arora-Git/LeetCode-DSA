// https://leetcode.com/problems/number-of-good-pairs/

// https://leetcode.com/problems/number-of-good-pairs/discuss/1685164/Simple-C%2B%2B-Solution

#include <iostream>
#include <vector>

using namespace std;

int numIdenticalPairs(vector<int> &nums)
{
    int size = nums.size();
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (nums[i] == nums[j])
                count++;
        }
    }

    return count;
}

int main()
{
    vector<int> nums = {1, 2, 3, 1, 1, 3};

    // 4
    cout << numIdenticalPairs(nums) << '\n';
    return 0;
}