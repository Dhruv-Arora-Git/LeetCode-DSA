// https://leetcode.com/problems/node-with-highest-edge-score/

// https://leetcode.com/problems/node-with-highest-edge-score/discuss/2499769/C%2B%2B-oror-O(N)-Without-Graph-oror-Counting

#include <iostream>
#include <vector>

using namespace std;

int edgeScore(vector<int> &edges)
{
    int n = edges.size();

    vector<long long> ans(n, 0);

    // ans[i] = sum of all the nodes that have an edge pointing to i.
    for (int i = 0; i < n; ++i)
        ans[edges[i]] += i;

    long long maxScore = 0, maxEdge = -1;
    // finding max
    for (int i = 0; i < n; ++i)
    {
        if (ans[i] > maxScore)
        {
            maxScore = ans[i];
            maxEdge = i;
        }
    }

    return maxEdge;
}
int main()
{
    vector<int> edges = {1, 0, 0, 0, 0, 7, 7, 5};

    cout << edgeScore(edges) << "\n";
    return 0;
}