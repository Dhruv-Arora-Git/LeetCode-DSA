// https://leetcode.com/problems/shuffle-the-array/

// https://leetcode.com/problems/shuffle-the-array/discuss/1685109/C%2B%2B-or-2-Pointer-or-100-fast-or-1-loop-or-commented
#include <iostream>
#include <vector>

using namespace std;

vector<int> shuffle(vector<int> &nums, int n)
{
    vector<int> ans;
    int size = nums.size();
    // pointer at 0
    int i = 0;
    // pointer at n ( size / 2 )
    int j = n;

    // pushing elements from 0 and n one by one
    while (i < n && j < size)
    {
        // pushing elements from 0 to n - 1
        ans.push_back(nums[i++]);
        // pushing eleentsfrom n to size - 1
        ans.push_back(nums[j++]);
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 4, 3, 2, 1};
    int n = 4;

    vector<int> answer = shuffle(nums, n);

    // {1,4,2,3,3,2,4,1}
    for (int i : answer)
        cout << i << " ";

    cout << '\n';

    return 0;
}