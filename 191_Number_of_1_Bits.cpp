// https://leetcode.com/problems/number-of-1-bits/

// https://leetcode.com/problems/number-of-1-bits/discuss/1650623/C%2B%2B-Bit-Manipulation-oror-Easy-oror-fastest

#include <iostream>
using namespace std;

int hammingWeight(uint32_t n)
{
    int count = 0;

    while (n != 0)
    {
        if (n & 1)
        {
            count++;
        }
        n = n >> 1;
    }
    return count;
}

int main()
{
    int n = 00000000000000000000000000001011;
    cout << hammingWeight(n) << '\n';
    return 0;
}