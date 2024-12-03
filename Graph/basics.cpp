#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void bfsUtil (vector<vector<int>>& graph, vector<bool>& visited, vector<int>& bfs_trav, int node) {
    int n = graph.size();
    queue<int> q;
    q.push(node);
    
    visited[node] = true;
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        bfs_trav.push_back(front);
        for (int i = 0; i < n; i++) {
            if (!visited[i] && graph[front][i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

vector<int> bfs (vector<vector<int>>& graph, int node) {
    vector<bool> visited (graph.size(), 0);
    vector<int> arr_bfs;
    bfsUtil(graph, visited, arr_bfs, node);
    return arr_bfs;
}

void dfsUtil(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& dfs_trav, int node) {
    if (!visited[node]) {
        dfs_trav.push_back(node);
        visited[node] = true;
    }
    for (int i = 0; i < graph.size(); i++) {
        if (!visited[i] && graph[node][i] == 1) {
            dfsUtil(graph, visited, dfs_trav, i);
        }
    }
}

vector<int> dfs (vector<vector<int>>& graph, int node) {
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<int> dfs_trav;
    dfsUtil(graph, visited, dfs_trav, node);
    return dfs_trav;
}

int main()
{
    vector<vector<int>> adjMatrix = {
        {0, 1, 1, 1, 0},  // Node 0 is connected to nodes 1, 2, and 3
        {1, 0, 0, 0, 0},  // Node 1 is connected to node 0
        {1, 0, 0, 0, 1},  // Node 2 is connected to nodes 0 and 4
        {1, 0, 0, 0, 0},  // Node 3 is connected to node 0
        {0, 0, 1, 0, 0}   // Node 4 is connected to node 2
    };
    vector<int> arr_dfs = dfs(adjMatrix, 0);
    vector<int> arr_bfs = bfs(adjMatrix, 0);

    cout << "BFS" << endl;
    for (int num : arr_bfs) cout << num << " ";
    cout << endl;
    cout << "DFS" << endl;
    for (int num : arr_dfs) cout << num << " ";
    return 0;
}