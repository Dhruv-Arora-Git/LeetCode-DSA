// https://leetcode.com/problems/remove-palindromic-subsequences/

// https://leetcode.com/problems/remove-palindromic-subsequences/discuss/2129983/C%2B%2B-0-or-1-or-2-oror-Explained-with-Comments

#include <iostream>
using namespace std;

int removePalindromeSub(string s)
{
    if (s.empty())
        return 0; // empty string, so 0 steps

    // check for palindrome
    int i = 0, j = s.length() - 1;

    while (i < j)
    {
        if (s[i++] != s[j--])
            return 2; // not a palindrome, remove all "a", then remove all "b", so 2 steps
    }

    return 1; // it's palindrome, so only 1 step
}

int main()
{
    string s = "baabb";

    cout << removePalindromeSub(s) << "\n";

    return 0;
}