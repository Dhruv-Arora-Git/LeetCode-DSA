// https://leetcode.com/problems/implement-strstr/

// https://leetcode.com/problems/implement-strstr/discuss/1713811/C%2B%2B-or-2-Lines-of-Code-or-find()-simplest-method
#include <iostream>
using namespace std;
int strStr(string haystack, string needle)
{
    if (needle == "")
        return 0;

    return haystack.find(needle);
}
int main()
{
    string haystack = "hello", needle = "ll";

    cout << strStr(haystack, needle) << '\n';
    return 0;
}