// https://leetcode.com/problems/find-numbers-with-even-number-of-digits/

// https://leetcode.com/problems/find-numbers-with-even-number-of-digits/discuss/1685234/C%2B%2B-Solution-or-simple-and-easy

#include <iostream>
#include <vector>

using namespace std;

int countDigits(int n)
{
    int cnt = 0;
    while (n != 0)
    {
        cnt++;
        n /= 10;
    }
    return cnt;
}
int findNumbers(vector<int> &nums)
{
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (countDigits(nums[i]) % 2 == 0)
            count++;
    }
    return count;
}

int main()
{
    vector<int> nums = {12, 345, 2, 6, 7896};
    // 2
    cout << findNumbers(nums) << '\n';
    return 0;
}