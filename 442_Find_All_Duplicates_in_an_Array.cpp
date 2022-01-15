// https://leetcode.com/problems/find-all-duplicates-in-an-array/

// https://leetcode.com/problems/find-all-duplicates-in-an-array/discuss/1687421/C%2B%2B-Cyclic-Sort-or-O(n)-time-or-constant-space

#include <iostream>
#include <vector>

using namespace std;

vector<int> findDuplicates(vector<int> &nums)
{
    vector<int> duplicates;
    int n = nums.size();

    // cyclc sort
    int i = 0;
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
        {
            duplicates.push_back(nums[i]);
        }
    }

    return duplicates;
}

int main()
{
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> duplicate = findDuplicates(nums);

    for (int i : duplicate)
        cout << i << " ";
    cout << '\n';
    return 0;
}