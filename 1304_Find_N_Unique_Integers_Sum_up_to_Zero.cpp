// https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/

// https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/discuss/1685204/C%2B%2B-Easy-Solution-or-with-Comments-or-100-fast-solution

#include <iostream>
#include <vector>

using namespace std;

vector<int> sumZero(int n)
{
    vector<int> zero;

    int a = n / 2;
    // n = 4
    // a = 2
    // i = -2, -1, 0, 1, 2, sum of these will always be = 0
    // as n(4) is even, 0 will be skipped
    for (int i = -a; i <= a; i++)
    {
        // if n is even, skip 0
        if (i == 0 && !(n & 1))
            continue;

        zero.push_back(i);
    }
    // final array : -2, -1, 1, 2

    return zero;
}

int main()
{
    int n = 5;
    vector<int> nums = sumZero(n);

    // {-2, -1, 0, 1, 2}
    for (int i : nums)
        cout << i << " ";
    cout << '\n';
    return 0;
}