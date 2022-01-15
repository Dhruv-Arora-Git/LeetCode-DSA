#include <iostream>
#include <vector>

using namespace std;
int findDuplicate(vector<int> &nums)
{
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

    return nums[n - 1];
}
int main()
{
    vector<int> nums = {1, 3, 4, 2, 2};
    cout << findDuplicate(nums) << '\n';
    return 0;
}