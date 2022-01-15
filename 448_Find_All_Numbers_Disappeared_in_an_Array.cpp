// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/discuss/1687351/C%2B%2B-Cyclic-Sort-or-O(n)-time-or-O(1)-space

// asked by google
#include <iostream>
#include <vector>

using namespace std;

vector<int> findDisappearedNumbers(vector<int> &nums)
{
    vector<int> missing;

    int n = nums.size();

    int i = 0;
    // cyclic sort
    while (i < n)
    {
        int index = nums[i] - 1;

        if (nums[i] != nums[index])
        {
            swap(nums[i], nums[index]);
        }
        else
        {
            i++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (nums[i] != i + 1)
            missing.push_back(i + 1);
    }

    return missing;
}

int main()
{
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> ans = findDisappearedNumbers(nums);

    for (int i : ans)
        cout << i << " ";
    cout << '\n';
    return 0;
}