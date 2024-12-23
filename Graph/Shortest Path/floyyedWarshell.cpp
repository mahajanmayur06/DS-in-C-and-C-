#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> floyyedWarshell (vector<vector<pair<int, int>>>& edges) {
    int n = edges.size();
    vector<vector<int>> cost (n, vector<int> (n, INT_MAX));
    for (int i = 0; i < n; i++) {
        cost[i][i] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (auto j : edges[i]) {
            cost[i][j.first] = j.second;
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (cost[i][k] == INT_MAX || cost[k][j] == INT_MAX) {
                    continue;
                }
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (cost[i][j] == INT_MAX) {
                cost[i][j] = -1;
            }
        }
    }

    return cost;
}

int main() {
    vector<vector<pair<int, int>>> adjList = {
        {{1, 2}},   
        {{0, 1}, {2, 3}},            
        {},           
        {{0, 3}, {1, 5}, {2, 4}},     
    };
    auto cost = floyyedWarshell(adjList);
    for (auto adj : cost) {
        for (int node : adj) {
            cout << node << " ";
        }
        cout << endl;
    }
    return 0;
}