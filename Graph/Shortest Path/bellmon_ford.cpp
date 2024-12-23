#include <bits/stdc++.h>
using namespace std;

vector<int> bellmon_ford (int v, vector<vector<int>>& edges, int src) {
    vector<int> dist(v, INT_MAX);
    dist[src] = 0;

    for (int i = 1; i < v - 1; i++) {
        for (auto it : edges) {
            int u = it[0], v = it[1];
            int wt = it[2];
            if (dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Nth iteration to check negative edge cycle
    bool isChange = false;
    for (auto it : edges) {
        for (auto it : edges) {
            int u = it[0], v = it[1];
            int wt = it[2];
            if (dist[u] + wt < dist[v]) {
                isChange = true;
                dist[v] = dist[u] + wt;
            }
        }
    }
    if (isChange) cout << "this graph has negative edge cycle";
    return dist;
}
int main()
{
    
    return 0;
}