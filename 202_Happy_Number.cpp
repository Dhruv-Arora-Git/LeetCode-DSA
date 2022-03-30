// https://leetcode.com/problems/happy-number/

// https://leetcode.com/problems/happy-number/discuss/1898122/Using-Fast-and-Slow-or-Comments-Added-or-Similar-to-cycle-detection-in-linked-list

#include <iostream>
using namespace std;

long long sumOfSquaresOfDigits(int num)
{
    long long ans = 0;

    while (num != 0)
    {
        int rem = num % 10;
        ans += (rem * rem);
        num /= 10;
    }
    return ans;
}

bool isHappy(int n)
{
    // it's like slow and fast pointers in linked list
    // as after some calculations, the num will start repeating
    // similar to cycle detection
    // so, with fast int, we are calculating square of digits twice and with slow once
    // and if the num is repeating, then slow and fast value will definitely becomes same
    // so we will break the loop
    // then we will check if the slow value is 1, then we will return true
    long long slow = n, fast = n;

    do
    {
        slow = sumOfSquaresOfDigits(slow);
        fast = sumOfSquaresOfDigits(sumOfSquaresOfDigits(fast));

        if (fast == 1 or slow == 1)
            return true;

    } while (slow != fast);

    if (slow == 1)
        return true;

    return false;
}

int main()
{
    int n = 19;
    cout << isHappy(n) << '\n';
    return 0;
}