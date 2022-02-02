// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/

// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/discuss/1662503/!00-faster-or-C%2B%2B-Solution-or-simple-loop-or-easy-to-understand

#include <iostream>
using namespace std;

int numberOfSteps(int num)
{
    int count = 0;
    while (num > 0)
    {
        if (num & 1) // condition to check odd integer
            num--;

        else
            num /= 2;

        count++;
    }

    return count;
}
int numberOfStepsRecusrive(int n, int count)
{
    if (n == 0)
        return count;

    if (n & 1)
        return numberOfStepsRecusrive(n - 1, ++count);

    return numberOfStepsRecusrive(n / 2, ++count);
}
int main()
{
    int num = 14;

    cout << numberOfStepsRecusrive(num, 0) << '\n';
    return 0;
}