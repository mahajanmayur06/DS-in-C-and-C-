#include <bits/stdc++.h>
using namespace std;

// disjoint set is used on dyanamic graphs, where configuration of graph changes
// it finds parent of a node, find union (by rank or by size)

// rank is number of nodes, beneath a node
// union(u, v) -->
// 1. find ultimate parents of u and v (pu, pv)
// 2. find ranks of pu and pv
// 3. Connect smaller rank to larger rank always

class DisjoinSet {
    vector<int> rank, parent, size;
public:
    DisjoinSet(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        size.resize(n, 1);
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

    void unionBySize (int u, int v) {
        int par_u = findUParent(u);
        int par_v = findUParent(v);
        if (par_u == par_v) {
            return;
        }
        
        if (size[par_u] < size[par_v]){
            parent[par_u] = parent[par_v];
            size[par_v] += size[par_u];
        }
        else {
            parent[par_v] = parent[par_u];
            size[par_u] += size[par_v];
        }
    } 
};

int main()
{
    DisjoinSet ds(5);
    ds.unionByRank(0, 2);
    ds.unionByRank(4, 2);
    ds.unionByRank(3, 1);
    if (ds.findUParent(4) == ds.findUParent(0)) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
    ds.unionByRank(0, 1);
    if (ds.findUParent(4) == ds.findUParent(0)) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }

    return 0;
}