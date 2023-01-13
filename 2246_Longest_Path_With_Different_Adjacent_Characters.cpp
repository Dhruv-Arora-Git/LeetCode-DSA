// https://leetcode.com/problems/longest-path-with-different-adjacent-characters/description/

// https://leetcode.com/problems/longest-path-with-different-adjacent-characters/discuss/3044386/c-picture-commented-solution-dfs-on-adj-list

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
int ans = 1;

int dfs(int currNode, int parent, string &labels)
{
    int maxPath = 1;

    for (int &node : adj[currNode])
    {
        if (node != parent)
        { // as adj list contains a edge to parent node as well, so to avoid an infinite loop

            int path = dfs(node, currNode, labels);

            if (labels[node] != labels[currNode])
            { // adjacent chars are not equal
                ans = max(ans, maxPath + path);
                maxPath = max(maxPath, path + 1);
            }
        }
    }

    return maxPath;
}

int longestPath(vector<int> &parent, string s)
{
    // creating adjacency list
    int n = parent.size();
    adj.resize(n);

    for (int i = 1; i < n; ++i)
    {
        adj[parent[i]].push_back(i); // i is bonded with its parent
        adj[i].push_back(parent[i]); // undirected, that's why 2 way binding
    }

    /*
        for ex1 - adj list =>
        0 -> 1, 2
        1 -> 0, 3, 4
        2 -> 5
        3 -> 1
        4 -> 1
    */

    dfs(0, -1, s);

    return ans;
}

int main()
{
    vector<int> parent = {-1, 0, 0, 1, 1, 2};
    string s = "abacbe";

    cout << longestPath(parent, s) << "\n";

    return 0;
}