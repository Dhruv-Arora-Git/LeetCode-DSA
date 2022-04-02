// https://leetcode.com/problems/valid-palindrome-ii/

// https://leetcode.com/problems/valid-palindrome-ii/discuss/1906515/C%2B%2B-Two-Pointer-Solution-or-Time-%3A-O(n)-Space-%3A-O(1)-or-Comments-Added-%3A)

#include <iostream>
using namespace std;

// Time: O(n), Space: O(1)
bool isPalindrome(const string &s, int start, int end)
{
    // 2 pointer approach to check palindrome

    int i = start, j = end;

    while (i <= j)
        if (s[i++] != s[j--])
            return false;

    return true;
}

bool validPalindrome(string s)
{
    int cnt = 0;

    int i = 0, j = s.length() - 1;

    bool res = false;

    while (i < j)
    {

        if (s[i] != s[j])
        {
            // if they are not equal, we will check if by removing 1 character, will give us a palindrome or not

            // try 1 : skipping/removing ith char
            res = isPalindrome(s, i + 1, j);

            if (res)
                return true;
            else
                // try 2 : skipping/removing jth char
                // and return it, as it's the final try
                return isPalindrome(s, i, j - 1);
        }

        // if (s[i] == s[j]) just move the pointers
        i++;
        j--;
    }

    // after the loop, we never hit (s[i] != s[j]) condition
    // therefore, it's a valid palindrome
    return true;
}

int main()
{
    // some test cases
    // "aydmda"
    // "eeccccbebaeeabebccceea"
    // "tcaac"
    // "ebcbbececabbacecbbcbe"
    string s = "ebcbbececabbacecbbcbe";

    cout << validPalindrome(s) << "\n";
    return 0;
}