// https://leetcode.com/problems/squares-of-a-sorted-array/

// https://leetcode.com/problems/squares-of-a-sorted-array/discuss/1650651/C%2B%2B-easy-to-understand-solution

#include <iostream>
#include <vector>

using namespace std;

vector<int> sortedSquares(vector<int> &nums)
{
    int n = nums.size();
    int left = 0;
    int right = n - 1;
    vector<int> sol(n);
    for (int i = n - 1; i >= 0; i--)
    {
        if (abs(nums[left]) > nums[right])
        {
            sol[i] = nums[left] * nums[left];
            left++;
        }
        else
        {
            sol[i] = nums[right] * nums[right];
            right--;
        }
    }

    return sol;
}

int main()
{
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> squares = sortedSquares(nums);
    for (int i : squares)
        cout << i << " ";
    cout << '\n';
    return 0;
}