#include <bits/stdc++.h>
using namespace std;

// 0 to n-1th node
string shortest_path (vector<vector<pair<int, int>>>& adjList) {
    int n = adjList.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0}); // distance, node
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;
    vector<int> parent (n);
    for (int i = 0; i < n; i++) parent[i] = i;
    while (!pq.empty()) {
        auto top = pq.top();
        int node = top.second;
        int distance = top.first;
        pq.pop();
        for (auto p : adjList[node]) {
            int d = p.second + distance;
            int adjNode = p.first;
            if (dist[adjNode] > d) {
                dist[adjNode] = d;
                pq.push({d, adjNode});
                parent[adjNode] = node;
            }
        }
    }   
    if (dist[n - 1] == INT_MAX) return "-1";
    int node = n - 1;
    string path = "0";
    while (parent[node] != node) {
        path += "." + to_string(node);
        node = parent[node];
    }
    return path;
}
int main()
{
    vector<vector<pair<int, int>>> adjList(6);

    // Adding edges to the adjacency list (undirected graph)
    adjList[0].push_back({1, 4}); // 0 -> 1 (weight 4)
    adjList[0].push_back({2, 1}); // 0 -> 2 (weight 1)

    adjList[1].push_back({0, 4}); // 1 -> 0 (weight 4)
    adjList[1].push_back({2, 2}); // 1 -> 2 (weight 2)
    adjList[1].push_back({3, 5}); // 1 -> 3 (weight 5)

    adjList[2].push_back({0, 1}); // 2 -> 0 (weight 1)
    adjList[2].push_back({1, 2}); // 2 -> 1 (weight 2)
    adjList[2].push_back({3, 8}); // 2 -> 3 (weight 8)
    adjList[2].push_back({4, 10}); // 2 -> 4 (weight 10)

    adjList[3].push_back({1, 5}); // 3 -> 1 (weight 5)
    adjList[3].push_back({2, 8}); // 3 -> 2 (weight 8)
    adjList[3].push_back({4, 2}); // 3 -> 4 (weight 2)
    adjList[3].push_back({5, 6}); // 3 -> 5 (weight 6)

    adjList[4].push_back({2, 10}); // 4 -> 2 (weight 10)
    adjList[4].push_back({3, 2}); // 4 -> 3 (weight 2)
    adjList[4].push_back({5, 3}); // 4 -> 5 (weight 3)

    adjList[5].push_back({3, 6}); // 5 -> 3 (weight 6)
    adjList[5].push_back({4, 3}); // 5 -> 4 (weight 3)

    string path = shortest_path(adjList);
    cout << path;
    return 0;
}