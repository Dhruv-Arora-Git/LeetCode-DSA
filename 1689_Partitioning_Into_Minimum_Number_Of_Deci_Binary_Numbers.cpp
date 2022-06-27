// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/

// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/discuss/2205692/Just-return-max-number-%2B-1-Liner-C%2B%2B

#include <iostream>
#include <algorithm>

using namespace std;

int minPartitions(string n)
{
    int mx = -1;

    for (const char &c : n)
        mx = max(mx, (c - '0'));

    return mx;
}

int minPartitions2(string n)
{
    return *max_element(n.begin(), n.end()) - '0';
}

int main()
{
    string n = "27346209830709182346";

    cout << minPartitions(n) << "\n";
    cout << minPartitions2(n) << "\n";

    return 0;
}