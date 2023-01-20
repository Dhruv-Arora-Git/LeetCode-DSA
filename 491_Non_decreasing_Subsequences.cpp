// https://leetcode.com/problems/non-decreasing-subsequences/

// https://leetcode.com/problems/non-decreasing-subsequences/discuss/3076461/C%2B%2B-Backtracking-%2B-Set-oror-Explained-in-Detail

#include <iostream>
#include <vector>
#include <set>

using namespace std;

set<vector<int>> st;

void rec(vector<int> &arr, int i, vector<int> &temp)
{
    if (i == arr.size())
    {
        if (temp.size() >= 2)
            st.insert(temp);
        return;
    }

    if (temp.empty() || (temp.back() <= arr[i]))
    {
        temp.push_back(arr[i]);
        rec(arr, i + 1, temp);
        temp.pop_back();
    }

    rec(arr, i + 1, temp);
}

vector<vector<int>> findSubsequences(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> temp;

    rec(nums, 0, temp);

    for (auto &vec : st)
    {
        ans.push_back(vec);
    }
    return ans;
}

int main()
{
    st.clear();

    vector<int> arr = {4, 6, 7, 7};
    vector<vector<int>> ans = findSubsequences(arr);

    for (auto &vec : ans)
    {
        for (auto &val : vec)
            cout << val << " ";
        cout << "\n";
    }

    return 0;
}