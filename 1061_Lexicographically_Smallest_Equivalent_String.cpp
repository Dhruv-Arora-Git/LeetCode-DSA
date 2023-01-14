// https://leetcode.com/problems/lexicographically-smallest-equivalent-string/

// https://leetcode.com/problems/lexicographically-smallest-equivalent-string/discuss/3048974/C%2B%2B-Union-Find-Variation-oror-Min-Parent

#include <iostream>
#include <vector>

using namespace std;

class DSU
{
private:
    vector<int> parent;

public:
    DSU()
    {
        parent = vector<int>(26, -1);
    }

    int find(int a)
    {
        if (parent[a] == -1)
            return a;

        return parent[a] = find(parent[a]);
    }

    void Union(int n1, int n2)
    {
        int r1 = find(n1);
        int r2 = find(n2);

        if (r1 != r2)
            parent[max(r1, r2)] = min(r1, r2);
    }
};

string smallestEquivalentString(string s1, string s2, string baseStr)
{
    DSU dsu;
    for (int i = 0; i < s1.size(); ++i)
    {
        int ch1 = s1[i] - 'a';
        int ch2 = s2[i] - 'a';
        dsu.Union(ch1, ch2);
    }

    for (int i = 0; i < baseStr.size(); ++i)
    {
        int mn = dsu.find(baseStr[i] - 'a');
        baseStr[i] = mn + 'a';
    }

    return baseStr;
}

int main()
{
    string s1 = "parker", s2 = "morris", baseStr = "parser";

    cout << smallestEquivalentString(s1, s2, baseStr) << "\n";
    return 0;
}