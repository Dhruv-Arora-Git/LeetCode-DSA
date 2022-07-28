// https://leetcode.com/problems/valid-anagram/

// https://leetcode.com/problems/valid-anagram/discuss/2343835/O(n)-Clean-Code-or-HashMap-or-Explained-C%2B%2B

#include <iostream>
#include <unordered_map>

using namespace std;

bool isAnagram(string s, string t)
{
    unordered_map<int, int> hash;

    for (const char &c : s)
        ++hash[c];

    for (const char &c : t)
        --hash[c];

    for (auto &it : hash)
        if (it.second != 0)
            return false;

    return true;
}

int main()
{
    string s = "anagram", t = "nagaram";

    cout << boolalpha << isAnagram(s, t) << "\n";

    return 0;
}