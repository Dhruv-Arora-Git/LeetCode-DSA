// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

// https://leetcode.com/problems/longest-substring-without-repeating-characters/solutions/3291327/c-simple-sliding-window-hash-map/?orderBy=most_votes

#include <iostream>
#include <unordered_map>
using namespace std;

bool check(unordered_map<char, int> &hash)
{
    for (auto &it : hash)
    {
        if (it.second > 1)
            return false;
    }
    return true;
}

int lengthOfLongestSubstring(string s)
{
    if (s.length() == 0)
        return 0;

    unordered_map<char, int> hash;
    int len = 1;
    int left = 0, right = 1;

    ++hash[s[left] - 'a'];
    ++hash[s[right] - 'a'];

    while (left < s.length() && right < s.length())
    {
        if (check(hash))
        {
            len = max(len, right - left + 1);
            ++right;

            if (right >= s.length())
                break;

            if (left != right)
                ++hash[s[right] - 'a'];
        }
        else
        {
            --hash[s[left] - 'a'];
            ++left;
            if (left >= s.length())
                break;
        }
    }

    return len;
}

int main()
{
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s) << "\n";
    return 0;
}