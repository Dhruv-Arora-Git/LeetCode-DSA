// https://leetcode.com/problems/valid-palindrome/

// https://leetcode.com/problems/valid-palindrome/discuss/1634090/C%2B%2B-2-Pointer-approach-O(1)-space-O(n)-time-solution

#include <iostream>
using namespace std;

bool validChar(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
    {
        return true;
    }
    return false;
}

char toLowerCase(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c - 'A' + 'a';
    else
        return c;
}

bool isPalindrome(string s)
{
    int i = 0;
    int j = s.length() - 1;
    while (i <= j)
    {
        while (!validChar(s[i]) && i < s.length() && i >= 0)
            i++;
        while (!validChar(s[j]) && j < s.length() && j >= 0)
            j--;

        if (toLowerCase(s[i]) == toLowerCase(s[j]))
        {
            i++;
            j--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string a;
    cin >> a;
    // cout << a.empty() << endl;
    cout << isPalindrome(a) << endl;
    return 0;
}