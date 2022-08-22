// https://leetcode.com/problems/keys-and-rooms/

// https://leetcode.com/problems/keys-and-rooms/discuss/2462750/just-do-a-simple-DFS-oror-Simple-and-Concise-Solution-C%2B%2B

#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &graph, int src, vector<bool> &visited)
{
    visited[src] = true;

    for (int &u : graph[src])
        if (visited[u] == false)
            dfs(graph, u, visited);
}

bool canVisitAllRooms(vector<vector<int>> &rooms)
{

    vector<bool> visited(rooms.size(), false);

    dfs(rooms, 0, visited);

    for (bool flag : visited)
        if (!flag)
            return false;

    return true;
}

int main()
{
    vector<vector<int>> rooms = {
        {1, 3},
        {3, 0, 1},
        {2},
        {0},
    };

    cout << boolalpha << canVisitAllRooms(rooms) << "\n";

    return 0;
}