#include <bits/stdc++.h>
using namespace std;

// using dfs
bool dfs (vector<vector<int>>& graph, int node, vector<bool> visited, vector<bool> path_visited) {
    visited[node] = true;
    path_visited[node] = true;
    for (int adjNode : graph[node]) {
        if (!visited[adjNode]) {
            if (dfs(graph, adjNode, visited, path_visited)) {
                return true;
            }
        }
        else if (path_visited[adjNode]) {
            return true;
        }
    }
    path_visited[node] = false;
    return false;
}

bool isCycle (vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false), path_visited(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(graph, i, visited, path_visited)) {
                return true;
            }
        }
    }
    return false;
}

// using bfs : kahns algorithm
int main() 
{
    vector<vector<int>> graph1 = {
        {1, 2},    // Node 0 points to Nodes 1 and 2
        {3},       // Node 1 points to Node 3
        {4, 5},    // Node 2 points to Nodes 4 and 5
        {6},       // Node 3 points to Node 6
        {2},       // Node 4 points to Node 2 (cycle)
        {},        // Node 5 has no outgoing edges
        {7},       // Node 6 points to Node 7
        {3}        // Node 7 points to Node 3 (cycle)
    };
    vector<vector<int>> graph2 = {
        {1, 2},    // Node 0 points to Nodes 1 and 2
        {3},       // Node 1 points to Node 3
        {4, 5},    // Node 2 points to Nodes 4 and 5
        {},        // Node 3 has no outgoing edges
        {6},       // Node 4 points to Node 6
        {7},       // Node 5 points to Node 7
        {},        // Node 6 has no outgoing edges
        {}         // Node 7 has no outgoing edges
    };
    cout << isCycle(graph1) << endl;
    cout << isCycle(graph2) << endl;
    return 0;
}