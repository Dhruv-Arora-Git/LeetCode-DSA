// https://leetcode.com/problems/similar-string-groups/description/

// https://leetcode.com/problems/similar-string-groups/solutions/3463081/c-dfs-super-clean-code-with-approach-explanation/

#include <iostream>
#include <vector>

using namespace std;

bool checkSame(string &s, string &t)
{
    int sz = size(s);
    int diff = 0;
    for (int i = 0; i < sz; ++i)
    {
        if (s[i] != t[i])
        {
            ++diff;
        }
        if (diff > 2)
            return false;
    }

    return (diff <= 2);
}

void dfs(vector<string> &strs, string &check)
{
    for (int i = 0; i < strs.size(); ++i)
    {
        if (strs[i] == "")
            continue;

        if (checkSame(strs[i], check))
        {
            string temp = strs[i];
            strs[i] = "";
            dfs(strs, temp);
        }
    }
}

int numSimilarGroups(vector<string> &strs)
{
    int n = strs.size();
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        if (strs[i] == "")
            continue;

        string temp = strs[i];
        strs[i] = "";

        cnt++;
        dfs(strs, temp);
    }

    return cnt;
}

int main()
{
    vector<string> strs = {"tars", "rats", "arts", "star"};

    cout << numSimilarGroups(strs) << "\n";
    return 0;
}