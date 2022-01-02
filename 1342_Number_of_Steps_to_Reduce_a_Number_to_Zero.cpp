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

int main()
{
    int num = 14;

    cout << numberOfSteps(num) << '\n';
    return 0;
}