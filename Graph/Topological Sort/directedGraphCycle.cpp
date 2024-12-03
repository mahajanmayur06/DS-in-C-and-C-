#include <bits/stdc++.h>
using namespace std;

bool isCycle(vector<vector<int>>& adjList) {
    int n = adjList.size();
    vector<int> indegree (n, 0);
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
    int cnt = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cnt++;
        for (int adjNode : adjList[node]) {
            indegree[adjNode]--;
            if (indegree[adjNode] == 0) {
                q.push(adjNode);
            }
        }
    }
    return cnt != n;
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

    cout << "Cycle: " << boolalpha << isCycle(adjList);
    return 0;
}