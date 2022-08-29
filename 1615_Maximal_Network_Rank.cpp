// https://leetcode.com/problems/maximal-network-rank/

// https://leetcode.com/problems/maximal-network-rank/discuss/2500167/Graph-Solution-Explained-with-Comments-C%2B%2B

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int maximalNetworkRank(int n, vector<vector<int>> &roads)
{
    if (roads.size() == 0)
        return 0;

    // taking unordered_set to check connection of edges in O(1) time
    vector<unordered_set<int>> adjList(n);

    for (auto &road : roads)
    {
        adjList[road[0]].insert(road[1]);
        adjList[road[1]].insert(road[0]);
    }

    int maxRank = 0;

    // checking each pair
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            // size shows edges, edges shows rank, simple :)
            int rank = adjList[i].size() + adjList[j].size();

            // checking connected, so there is an edge common b/w both, so just consider it once only, NOT twice
            if (adjList[i].count(j))
                --rank;

            maxRank = max(maxRank, rank);
        }
    }
    return maxRank;
}

int main()
{
    int n = 8;
    vector<vector<int>> roads = {{0, 1}, {1, 2}, {2, 3}, {2, 4}, {5, 6}, {5, 7}};

    cout << maximalNetworkRank(n, roads) << "\n";

    return 0;
}