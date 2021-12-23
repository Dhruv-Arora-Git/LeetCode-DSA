#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int> &nums)
{

    if (nums.size() == 1)
        return;

    int i = 0, j = 0;
    int n = nums.size();

    while (i < n && j < n)
    {

        while (nums[i] != 0)
            i++;
        while (nums[j] == 0)
            j++;
        if (i > j && j < n)
            j = i + 1;

        if (nums[i] == 0 and nums[j] != 0)
        {
            swap(nums[i], nums[j]);
            i++;
            j++;
        }
    }
}

int main()
{
    vector<int> v = {1, 0, 2, 0, 3, 0};
    moveZeroes(v);

    for (int i : v)
        cout << i << " ";
    cout << '\n';
    return 0;
}