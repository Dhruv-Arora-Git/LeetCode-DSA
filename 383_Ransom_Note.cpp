// https://leetcode.com/problems/ransom-note/

// https://leetcode.com/problems/ransom-note/discuss/2038518/C%2B%2B-O(n)-Solution-Easy-to-Understand

#include <iostream>
#include <unordered_map>

using namespace std;

bool canConstruct(string ransomNote, string magazine)
{
    // hashmap to store count of each char
    unordered_map<char, int> mp;

    for (char &c : magazine)
    {
        mp[c]++;
    }

    for (char &a : ransomNote)
    {
        auto it = mp.find(a);
        // if it's NOT in the map or it's freq <= 0 (already used)
        if (it == mp.end() || it->second <= 0)
            return false;

        mp[a]--; // reducing it's frequency
    }

    return true;
}

int main()
{
    cout << canConstruct("aa", "aab") << "\n";
    return 0;
}