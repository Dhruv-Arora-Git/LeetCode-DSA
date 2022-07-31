// https://leetcode.com/problems/first-letter-to-appear-twice/

// https://leetcode.com/problems/first-letter-to-appear-twice/discuss/2359683/C%2B%2B-HashSet-or-O(n)-time-or-Explained

#include <iostream>
#include <unordered_set>

using namespace std;

char repeatedCharacter(string s)
{
    unordered_set<char> set;

    for (const char &c : s)
    {
        if (set.count(c) > 0)
            return c;

        set.insert(c);
    }
    return '#'; // if no char is repeated
}

int main()
{
    string s = "abccbaacz";

    cout << repeatedCharacter(s) << "\n";

    return 0;
}