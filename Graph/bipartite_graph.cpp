#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// using dfs traversal
bool dfs (vector<vector<int>>& adj, int node, int col, vector<int>& color) {
    color[node] = col;
    for (int adjNode : adj[node]) {
        if (color[adjNode] == -1) {
            if (!dfs(adj, adjNode, !col, color)) { // this should return false
                return false;
            }
        }
        else if (color[adjNode] == col) {
            return false;
        }
    }
    return true;
}

bool isBipartiteDFS(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> color (n, -1);
    for (int i = 0; i < n; i++) {
        if (color[i] == -1 && !dfs(adj, i, 0, color)) {
            return false;
        }
    }
    return true;
}

// using bfs traversal
bool bfs (vector<vector<int>>& adj, int V, int st, vector<int>& color) {
    queue<int> q;
    q.push(st);
    color[st] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto adjNode : adj[node]) {
            if (color[adjNode] == -1) {
                q.push(adjNode);
                color[adjNode] = !color[node];
            }
            else if (color[adjNode] == color[node]){
                return false;
            }
        }
    }
    return true;
}
bool isBipartiteBFS(vector<vector<int>>& adj){
    // Code here
    int V = adj.size();
    vector<int> color(V, -1);
    for (int i = 0; i < V; i++) {
        if (color[i] == -1 && !bfs(adj, V, i, color)) {
            return false;
        }
    }
    return true;
}
int main()
{
    // Example 1: Bipartite Graph
    vector<vector<int>> adjList1 = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}
    };

    // Example 2: Not a Bipartite Graph
    vector<vector<int>> adjList2 = {
        {1, 2},
        {0, 2},
        {0, 1, 3},
        {2}
    };
    cout << boolalpha << isBipartiteBFS(adjList1) << " " << isBipartiteBFS(adjList2) << endl;
    cout << boolalpha << isBipartiteDFS(adjList1) << " " << isBipartiteDFS(adjList2) << endl;
    return 0;
}