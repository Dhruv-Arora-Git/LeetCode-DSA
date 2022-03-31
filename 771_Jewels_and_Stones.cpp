// https://leetcode.com/problems/jewels-and-stones/

// https://leetcode.com/problems/jewels-and-stones/discuss/1901102/C%2B%2B-HashMap-Solution-or-Commented-Explanation-%3A)

#include <iostream>
#include <unordered_map>

using namespace std;

int numJewelsInStones(string jewels, string stones)
{
    // it will store count of characters in string 'stones'
    unordered_map<char, int> cnt;

    for (const char &c : stones)
    {
        cnt[c]++;
    }

    int count = 0;

    for (const char &c : jewels)
    {
        // we are checking the chars of jewels in cnt(that is count of chars of 'stones')
        // 'it' will have a value if char c of jewls is present in cnt ('stones')
        // else 'it' will be cnt.end()
        auto it = cnt.find(c);

        // if 'it' is not cnt.end() then we are incrementing count by value of 'it'
        if (it != cnt.end())
            count += it->second;
    }

    return count;
}

int main()
{
    string jewels = "aA";
    string stones = "aAAbbbb";

    cout << numJewelsInStones(jewels, stones) << "\n";
    return 0;
}