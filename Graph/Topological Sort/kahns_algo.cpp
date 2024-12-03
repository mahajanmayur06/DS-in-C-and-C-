#include <bits/stdc++.h>
using namespace std;

// we can use this to schedule tasks, providing we had given pairs of tasks

vector<int> topologicalSort(vector<vector<int>>& adjList) {
    int n = adjList.size();
    vector<int> indegree (n, 0);
    vector<int> topo;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        for (int node : adjList[i]) {
            indegree[node]++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (int adjNode : adjList[node]) {
            indegree[adjNode]--;
            if (indegree[adjNode] == 0) {
                q.push(adjNode);
            }
        }
    }
    return topo;
}

int main() {
    int n = 6;
    vector<vector<int>> adjList(n);

    // Adding edges
    adjList[5] = {0, 2};
    adjList[4] = {0, 1};
    adjList[3] = {1};
    adjList[2] = {3};
    adjList[1] = {};
    adjList[0] = {};

    vector<int> topo_sort = topologicalSort(adjList);
    for (int num : topo_sort) cout << num << " ";
    return 0;
}