// https://leetcode.com/problems/group-anagrams/

// https://leetcode.com/problems/group-anagrams/discuss/2459257/C%2B%2B-unordered_map-and-Sorting-oror-Commented-Concise-Solution

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    // the sorted string -> vector of anamgram strings
    unordered_map<string, vector<string>> mapping;

    for (string &s : strs)
    {
        string temp = s;
        sort(temp.begin(), temp.end()); // sorted string will act as key for all it's Anagrams

        mapping[temp].push_back(s);
    }

    vector<vector<string>> v;

    // making vector from hashmap
    for (auto &it : mapping)
        v.push_back(it.second); // it.second is the vector of grouped anagrams

    return v;
}

int main()
{

    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> v = groupAnagrams(strs);

    for (auto &vec : v)
    {
        for (auto &str : vec)
            cout << str << " ";
        cout << "\n";
    }
    return 0;
}