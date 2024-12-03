#include <bits/stdc++.h>
using namespace std;

vector<int> shortest_distance (vector<vector<int>>& adjList, int src) {
    int n = adjList.size();
    vector<int> dist (n, INT_MAX);
    dist[src] = 0;
    queue<pair<int, int>> q;
    q.push({src, 0});
    while (!q.empty()) {
        int node = q.front().first;
        int w = q.front().second;
        q.pop();
        for (int adjNode : adjList[node]) {
            if (dist[node] + 1 < dist[adjNode]) {
                dist[adjNode] = dist[node] + 1;
                q.push({adjNode, dist[adjNode]});
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) {
            dist[i] = -1;
        }
    }
    return dist;
}

vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
    // code here
    vector<vector<int>> adjList(N);
    for (auto it : edges) {
        adjList[it[0]].push_back(it[1]);
        adjList[it[1]].push_back(it[0]);
    }
    return shortest_distance(adjList, src);
}
int main()
{
    
    return 0;
}