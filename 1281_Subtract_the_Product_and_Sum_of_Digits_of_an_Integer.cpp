#include <iostream>
using namespace std;

int subtractProductAndSum(int n)
{
    int sum = 0, product = 1;

    while (n != 0)
    {
        int digit = n % 10;
        sum += digit;
        product *= digit;

        n /= 10;
    }

    return (product - sum);
}

int main()
{
    int n = 4421;
    cout << subtractProductAndSum(n) << '\n';
    return 0;
}