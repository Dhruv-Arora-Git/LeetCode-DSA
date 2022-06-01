// https://leetcode.com/problems/find-the-k-beauty-of-a-number/

// https://leetcode.com/problems/find-the-k-beauty-of-a-number/discuss/2098790/C%2B%2B-oror-Sliding-Window-oror-0ms-oror-Comments-Added

#include <iostream>
using namespace std;

int divisorSubstrings(int num, int k)
{
    string s = to_string(num);
    int n = (int)s.length();

    int cnt = 0;

    // taking window of size k
    for (int i = 0; i <= n - k; ++i)
    {
        // taking out substring of size k and converting it to int
        string temp = s.substr(i, k);
        int t = stoi(temp);

        if (t == 0) // to not get div by 0 error
            continue;

        // check if num is divisible by t
        if (num % t == 0)
            cnt++;
    }

    return cnt;
}

int main()
{
    int num = 240;
    int k = 2;

    cout << divisorSubstrings(num, k) << "\n";

    return 0;
}