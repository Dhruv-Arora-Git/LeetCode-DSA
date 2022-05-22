// https://leetcode.com/problems/find-if-path-exists-in-graph/

// https://leetcode.com/problems/find-if-path-exists-in-graph/discuss/2064472/The-classic-BFS-traversal-oror-Clean-Code-C%2B%2B

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void createGraph(vector<vector<int>> &edges, vector<vector<int>> &graph)
{
    for (int i = 0; i < edges.size(); ++i)
    {
        int u = edges[i][0], v = edges[i][1];

        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

bool bfs(vector<vector<int>> &graph, int source, int destination)
{
    vector<bool> visited(graph.size(), false);

    queue<int> q;
    q.push(source);
    visited[source] = true;

    while (!q.empty())
    {
        int edge = q.front();
        q.pop();

        for (int v : graph[edge])
        {
            if (visited[v] == false)
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    return visited[destination];
}

bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
{
    vector<vector<int>> graph(n);

    createGraph(edges, graph);

    return bfs(graph, source, destination);
}

int main()
{
    int n = 6;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}};
    int source = 0, destination = 5;

    cout << validPath(n, edges, source, destination) << "\n";
    return 0;
}