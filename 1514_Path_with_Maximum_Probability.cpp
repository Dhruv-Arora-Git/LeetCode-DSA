// https://leetcode.com/problems/path-with-maximum-probability/

// https://leetcode.com/problems/path-with-maximum-probability/discuss/2419636/C%2B%2B-BFS-(Djikstra)-oror-Explained-with-Comments

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <float.h>

using namespace std;

class Node
{
public:
    int vertex;
    double weight;

    Node(int v, double w)
    {
        vertex = v;
        weight = w;
    }
};

vector<double> dijkstra(unordered_map<int, vector<Node>> &graph, int n, int src)
{
    vector<double> probability(n, DBL_MIN); // DBL_MIN is the minimum value of double in C++

    probability[src] = 1.0; // we are already on it

    queue<Node> q;

    q.push(Node(src, 1.0));

    while (!q.empty())
    {

        int sz = q.size();

        while (sz--)
        {
            Node currNode = q.front();
            q.pop();

            for (auto &nextNode : graph[currNode.vertex])
            {
                // if we found a better probability, update it and push to the queue
                if (probability[currNode.vertex] * nextNode.weight > probability[nextNode.vertex])
                {
                    q.push(Node(nextNode.vertex, probability[currNode.vertex] * nextNode.weight));
                    probability[nextNode.vertex] = probability[currNode.vertex] * nextNode.weight;
                }
            }
        }
    }
    return probability;
}

double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
{
    unordered_map<int, vector<Node>> graph;

    int i = 0; // just to iterate over succProb

    for (auto &edge : edges)
    {
        graph[edge[0]].push_back(Node(edge[1], succProb[i]));
        graph[edge[1]].push_back(Node(edge[0], succProb[i++]));
    }

    vector<double> probability = dijkstra(graph, n, start);

    // if it's still DBL_MIN, it means it's impossible to visit it, so probabilty is 0
    return probability[end] == DBL_MIN ? 0 : probability[end];
}

int main()
{
    int n = 3;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {0, 2}};
    vector<double> succProb = {0.5, 0.5, 0.2};

    cout << maxProbability(n, edges, succProb, 0, 2) << "\n";

    return 0;
}