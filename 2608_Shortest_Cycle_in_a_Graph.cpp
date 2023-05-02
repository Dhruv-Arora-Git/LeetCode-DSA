// https://leetcode.com/problems/shortest-cycle-in-a-graph/

// https://leetcode.com/problems/shortest-cycle-in-a-graph/discuss/3478880/C%2B%2B-Approach-Explained-oror-BFS

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int findShortestCycle(int n, vector<vector<int>>& edges) {
    unordered_map<int, vector<int>> graph;
    
    for(const auto &edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    
    int minCycle = 1e9;
    for(int i = 0; i < n; ++i) {
        vector<int> dist(n, 1e9);
        vector<int> parent(n, -1);
        
        queue<int> q;
        q.push(i);
        dist[i] = 0;

        while(!q.empty()) {
            int sz = q.size();
            
            while(sz--) {
                int curr = q.front(); q.pop();

                for(int &next : graph[curr]) {                        
                    if(dist[next] == 1e9) {
                        dist[next] = dist[curr] + 1;
                        parent[next] = curr;
                        q.push(next);
                    }
                    else if(parent[next] != curr && parent[curr] != next) {
                        int cycle = 1 + dist[next] + dist[curr];
                        minCycle = min(minCycle, cycle);
                    }
                }
            }
        }
    }
    return minCycle == 1e9 ? -1 : minCycle;
}

int main() {
	int n = 7;
    vector<vector<int>> edges = {{0,1},{1,2},{2,0},{3,4},{4,5},{5,6},{6,3}};
    cout << findShortestCycle(n, edges) << "\n";
	return 0;
}
    
    
    