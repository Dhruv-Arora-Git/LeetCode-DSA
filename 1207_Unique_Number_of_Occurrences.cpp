// https://leetcode.com/problems/unique-number-of-occurrences/

// https://leetcode.com/problems/unique-number-of-occurrences/discuss/2862160/C%2B%2B-Simple-HashMap-%2B-HashSet-oror-Efficient-O(n)

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

bool uniqueOccurrences(vector<int> &arr)
{
    unordered_map<int, int> freq;

    for (const int &i : arr)
        ++freq[i];

    unordered_set<int> st;

    for (const auto &it : freq)
    {
        if (st.find(it.second) != st.end())
            return false; // duplicate

        st.insert(it.second);
    }

    return (st.size() == freq.size());
}

int main()
{
    vector<int> arr = {1, 2, 2, 1, 1, 3};

    cout << boolalpha << uniqueOccurrences(arr) << "\n";

    return 0;
}