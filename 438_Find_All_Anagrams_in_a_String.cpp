// https://leetcode.com/problems/find-all-anagrams-in-a-string/

// https://leetcode.com/problems/find-all-anagrams-in-a-string/discuss/3144159/C%2B%2B-Brute-Force-andand-Optimised-Sliding-Window

#include <iostream>
#include <vector>

using namespace std;

// 1. Brue Force - Accepted ✅
vector<int> findAnagrams(string s, string p)
{
    vector<int> ans;

    vector<int> count(26, 0);

    for (char &c : p)
        count[c - 'a']++;

    for (int i = 0; i < s.length(); ++i)
    {
        vector<int> hash(26, 0);

        for (int j = i; j < i + p.length() && j < s.length(); ++j)
            hash[s[j] - 'a']++;

        if (hash == count)
            ans.push_back(i);
    }

    return ans;
}

/*
    2. Optimised Sliding Window - Accepted ✅
    Taking only one hash array for sliding window, and removing the char out of window, and adding the char in the window, on the go
*/
vector<int> findAnagrams2(string s, string p)
{
    int window = p.size();
    int len = s.size();

    if (window > len)
        return {};

    vector<int> hash(26, 0);
    vector<int> windowHash(26, 0);

    for (int i = 0; i < window; ++i)
    {
        ++hash[p[i] - 'a'];
        ++windowHash[s[i] - 'a'];
    }

    vector<int> ans;

    if (hash == windowHash)
        ans.push_back(0);

    for (int i = window; i < len; ++i)
    {
        --windowHash[s[i - window] - 'a'];
        ++windowHash[s[i] - 'a'];

        if (hash == windowHash)
            ans.push_back(i - window + 1);
    }

    return ans;
}

int main()
{
    string s = "cbaebabacd";
    string p = "abc";

    vector<int> ans = findAnagrams(s, p);

    for (int &i : ans)
        cout << i << " ";
    cout << "\n";

    return 0;
}