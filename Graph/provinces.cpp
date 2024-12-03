#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void bfs (vector<vector<int>>& isConnected, vector<bool>& visited, int node) {
    int n = isConnected.size();
    queue<int> q;
    q.push(node);
    visited[node] = true;
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        for (int i = 0; i < n; i++) {
            if (!visited[i] && isConnected[front][i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }

}

int find (vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<bool> visited(n, false);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bfs(isConnected, visited, i);
            count++;
        }
    }
    return count;
}

int main() {
    return 0;
}