// https://leetcode.com/problems/reordered-power-of-2/

// https://leetcode.com/problems/reordered-power-of-2/discuss/2512264/Clever-Solution-or-Convert-to-string-C%2B%2B

#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool reorderedPowerOf2(int n)
{
    unordered_set<string> powers = {
        "1", "2", "4", "8", "16", "32", "64", "128", "256", "512", "1024", "2048", "4096", "8192", "16384", "32768", "65536", "131072", "262144", "524288", "1048576", "2097152", "4194304", "8388608", "16777216", "33554432", "67108864", "134217728", "268435456", "536870912", "1073741824", "2147483648"};

    string num = to_string(n);
    sort(num.begin(), num.end());

    for (string s : powers)
    {
        sort(s.begin(), s.end());

        if (num == s)
            return true;
    }
    return false;
}

int main()
{
    int n = 46;

    cout << boolalpha << reorderedPowerOf2(n) << "\n";

    return 0;
}