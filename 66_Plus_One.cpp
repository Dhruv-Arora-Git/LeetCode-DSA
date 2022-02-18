// https://leetcode.com/problems/plus-one/

// https://leetcode.com/problems/plus-one/discuss/1779915/Simple-C%2B%2B-Solution-with-Comments-%3A)-for-beginners

#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int> &digits)
{
    int n = digits.size();
    // if last digits is not 9, just increase it
    // ex - 987 => 988
    if (digits[n - 1] < 9)
    {
        digits[n - 1]++;
        return digits;
    }

    vector<int> ans(n + 1, 0); // vector declared with all 0s, for all 9s case

    int cnt9 = 0;
    for (int i = 0; i < n; i++)
    {
        if (digits[i] == 9)
            cnt9++;
    }
    // if all are not 9s
    // ex - 99989 => 99990
    if (cnt9 < n)
    {
        int index = n - 1;
        while (index > 0 && digits[index] == 9)
        {
            digits[index--] = 0;
        }
        digits[index]++;
    }
    else if (cnt9 == n)
    {               // if all are 9s, we have to increase the size array, 999 => 1000
        ans[0] = 1; // vector was already filled with 0s, just make first index = 1
        // ex - 999 => 1(000)
        return ans;
    }

    return digits;
}

int main()
{
    vector<int> digits = {9, 9, 9, 9};
    vector<int> ans = plusOne(digits);

    for (int i : ans)
        cout << i << ' ';
    cout << '\n';

    return 0;
}