#include <bits/stdc++.h>
using namespace std;

// Sort edges by weight
class DisjointSet {
public:
    vector<int> rank, parent;
    DisjointSet(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int findUParent (int n) {
        if (parent[n] == n) {
            return parent[n];
        }
        parent[n] = findUParent(parent[n]);
        return parent[n];
    }   
    void unionByRank (int u, int v) {
        int par_u = findUParent(u);
        int par_v = findUParent(v);
        if (par_u == par_v) {
            return;
        }
        if (rank[par_u] < rank[par_v]){
            parent[par_u] = parent[par_v];
        }
        else if (rank[par_u] > rank[par_v]) {
            parent[par_v] = parent[par_u];
        }
        else {
            parent[par_v] = parent[par_u];
            rank[par_u]++;
        }
    }
};

vector<pair<int, int>> mst (vector<pair<int, pair<int, int>>> edges, int n) {
    vector<pair<int, int>> result;
    DisjointSet ds(n);
    sort(edges.begin(), edges.end());
    int sum = 0;
    for (auto edge : edges) {
        int u = edge.second.first;
        int v = edge.second.second;
        if (ds.findUParent(u) != ds.findUParent(v)) {
            result.push_back(edge.second);
            sum += edge.first;
            ds.unionByRank(u, v);
        }
    }
    cout << sum << endl;
    return result;
}

int main()
{
    vector<pair<int, pair<int, int>>> edges = {{1, {0, 1}}, {2, {1, 2}}, {3, {0, 2}}, {4, {0, 3}}, {5, {1, 3}}, {6, {2, 3}}}; // {weight, {u, v}}
    vector<pair<int, int>> result = mst(edges, 4);
    for (auto edge : result) {
        cout << edge.first << " " << edge.second << endl; // 1 0, 2 1, 4 0
    }

    return 0;
}