// https://leetcode.com/problems/sort-characters-by-frequency/

// https://leetcode.com/problems/sort-characters-by-frequency/discuss/2433276/My-Approach-with-multimap-or-Explained-C%2B%2B

#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

string frequencySort(string s)
{

    unordered_map<char, int> freq;

    // counting the frequency of each character
    for (const char &c : s)
        ++freq[c];

    // multimap allows duplicate keys (if 2 or more chars have same freq, they will not cause collision)
    // greater<int> make it sorted in decreasing order
    multimap<int, char, greater<int>> sorted;

    // sorting according to the frequency (as map stores in sorted order)
    for (auto &it : freq)
        sorted.insert({it.second, it.first});

    string ans = "";

    for (auto &it : sorted)
    {
        int i = it.first; // freq of char

        while (i--)
            ans.push_back(it.second); // push that char freq time in ans string
    }

    return ans;
}

int main()
{
    string s = "tree";
    cout << frequencySort(s) << "\n";

    return 0;
}