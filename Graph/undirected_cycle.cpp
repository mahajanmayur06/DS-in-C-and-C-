#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// using bfs
bool bfs(vector<vector<int>>& adjList, vector<bool>& visited, int src) {
    int n = adjList.size();
    queue<pair<int, int>> q;
    
    q.push({src, -1});
    visited[src] = true;

    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        int node = front.first;
        int parent = front.second;

        for (int adjNode : adjList[node]) {
            if (!visited[adjNode]) {
                visited[adjNode] = true;
                q.push({adjNode, node});
            } 
            else if (adjNode != parent) {
                return true;
            }
        }
    }
    return false;
}

bool isCycle(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i] && bfs(adj, visited, i)) {
            return true;
        }
    }
    return false;
}

// using dfs
bool dfsUtil (vector<vector<int>>& adjList, vector<bool>& visited, int node, int parent) {
    visited[node] = true;
    
    for (auto adjNode : adjList[node]) {
        if (!visited[adjNode]) {
            if (dfsUtil(adjList, visited, adjNode, node)) {
                return true;
            }
        }
        else if (parent != adjNode) {
            return true;
        }
        
    }
    return false;
}

bool dfs (vector<vector<int>>& adjList) {
        // Code here
    int n = adjList.size();
    vector<bool> visited(n, false);
    for (int i = 0; i < adjList.size(); i++) {
        if (!visited[i]) {
            if (dfsUtil(adjList, visited, i, -1))
                return true;
        }
    }
    return false;
}


int main() {
    vector<vector<int>> adjList = {
        {1, 2},     // Node 0 connected to 1, 2
        {},         // Node 1 is no longer connected to any other nodes
        {3, 5},     // Node 2 connected to 3, 5
        {},         // Node 3 is no longer connected to node 2
        {6},        // Node 4 connected to 6
        {7},        // Node 5 connected to 7
        {}          // Node 6 and Node 7 have no connections
    };

    cout << boolalpha << isCycle(adjList) << endl; // Expected output: false
    return 0;
}
