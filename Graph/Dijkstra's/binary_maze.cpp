#include <bits/stdc++.h>
using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    if (grid[0][0] == 1) return -1;
    int n = grid.size();
    vector<vector<int>> dist (n, vector<int> (n, INT_MAX));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({1, {0, 0}});
    dist[0][0] = 1;
    while (!pq.empty()) {
        int steps = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int newX = x + i;
                int newY = y + j;
                if (newX >= 0 && newY >= 0 && newX < n && newY < n && grid[newX][newY] == 1) {
                    if (dist[newX][newY] > steps + 1) {
                        dist[newX][newY] = steps + 1;
                        pq.push({dist[newX][newY], {newX, newY}});
                    }
                }
            }
        }
    }

    int ans = dist[n - 1][n - 1];
    return ans != INT_MAX ? ans : -1;
}

int main()
{
    
    return 0;
}