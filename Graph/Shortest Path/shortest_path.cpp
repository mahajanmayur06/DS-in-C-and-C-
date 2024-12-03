#include <bits/stdc++.h>
using namespace std;

void dfs (vector<vector<pair<int, int>>>& adjList, vector<bool>& visited, int node, stack<int>& st) {
    visited[node] = true;
    for (auto p : adjList[node]) {
        if (!visited[p.first]) {
            dfs (adjList, visited, p.first, st);
        }
    }
    st.push(node);
}

vector<int> shortestPath (vector<vector<pair<int, int>>>& adjList, int src) {
    int n = adjList.size();
    vector<bool> visited(n, false);
    stack <int> st;
    // Find topological Sort for DAG
    for (int i = 0; i < n; i++) {
        dfs (adjList, visited, i, st);
    }

    // define distance array
    vector<int> distance (n, INT_MAX);
    distance[src] = 0;
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        for (auto p : adjList[node]) {
            int w = distance[node] + p.second;
            if (w < distance[p.first]) {
                distance[p.first] = w;
            }
        }
    }
    return distance;
}
int main()
{
    vector<vector<pair<int, int>>> adjList1 = {
        {{1, 1}, {2, 4}},       // Node 0: (0→1, weight=1), (0→2, weight=4)
        {{2, 2}, {3, 6}},       // Node 1: (1→2, weight=2), (1→3, weight=6)
        {{3, 3}},               // Node 2: (2→3, weight=3)
        {}                      // Node 3: No outgoing edges
    };
    vector<vector<pair<int, int>>> adjList2 = {
        {{1, 3}, {2, 6}},       // Node 0: (0→1, weight=3), (0→2, weight=6)
        {{2, 2}, {3, 1}},       // Node 1: (1→2, weight=2), (1→3, weight=1)
        {{4, 2}},               // Node 2: (2→4, weight=2)
        {{4, 5}, {5, 1}},       // Node 3: (3→4, weight=5), (3→5, weight=1)
        {{6, 4}},               // Node 4: (4→6, weight=4)
        {{6, 1}, {7, 8}},       // Node 5: (5→6, weight=1), (5→7, weight=8)
        {{7, 2}},               // Node 6: (6→7, weight=2)
        {}                      // Node 7: No outgoing edges
    };
    vector<int> dist1 = shortestPath(adjList1, 0), dist2 = shortestPath(adjList2, 0);
    for (int num : dist1) cout << num << " ";
    cout << endl;
    for (int num : dist2) cout << num << " ";
    cout << endl;
    return 0;
}