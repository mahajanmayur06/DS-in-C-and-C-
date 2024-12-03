#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adjList, vector<bool>& visited, stack<int>& st, int node) {
    visited[node] = true;
    for (auto adjNode : adjList[node]) {
        if (!visited[adjNode]) {
            dfs (adjList, visited, st, adjNode);
        }
    }
    st.push(node);
}

vector<int> topologicalSort (vector<vector<int>>& adjList) {
    int n = adjList.size();
    stack<int> st;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs (adjList, visited, st, i);
        }
    }
    
    vector<int> arr;
    while (!st.empty()) {
        arr.push_back(st.top());
        st.pop();
    }
    return arr;
}

int main()
{
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