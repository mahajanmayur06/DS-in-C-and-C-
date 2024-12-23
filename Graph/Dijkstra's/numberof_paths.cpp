#include <bits/stdc++.h>
using namespace std;

int MOD = (int)1e9 + 7;

int countPaths (int n, vector<vector<int>>& roads) {
    vector<vector<pair<int, int>>> adjList(n);
    for (auto r : roads) {
        adjList[r[0]].push_back({r[1], r[2]});
        adjList[r[1]].push_back({r[0], r[2]});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n, INT_MAX);
    vector<int> ways(n, 0);
    dist[0] = 0;
    ways[0] = 1;
    pq.push({0, 0}); // time node
    while (!pq.empty()) {
        int node = pq.top().second;
        int time = pq.top().first;
        pq.pop();
        for (auto p : adjList[node]) {
            int t = p.second + time;
            int adjNode = p.first;
            if (dist[adjNode] > t) {
                dist[adjNode] = t;
                ways[adjNode] = ways[node];
                pq.push({t, adjNode});
            }
            else if (dist[adjNode] == t) {
                ways[adjNode] += ways[node];
            }
        }
    }
    return ways[n - 1] != INT_MAX ? ways[n - 1] % MOD : -1; 
}
int main()
{
    int n = 7;
    vector<vector<int>> roads = {
        {0, 6, 7},
        {0, 1, 2},
        {1, 2, 3},
        {1, 3, 3},
        {6, 3, 3},
        {3, 5, 1},
        {6, 5, 1},
        {2, 5, 1},
        {0, 4, 5},
        {4, 6, 2}
    };    
    cout << countPaths(n, roads);
    return 0;
}