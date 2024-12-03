#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void bfs (vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = true;
    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        if (row > 0 && grid[row - 1][col] == '1' && !visited[row - 1][col]) {
            visited[row-1][col] = true;
            q.push({row - 1, col});
        }
        if (row < n - 1 && grid[row + 1][col] == '1' && !visited[row + 1][col]) {
            visited[row + 1][col] = true;
            q.push({row + 1, col});
        }
        if (col > 0 && grid[row][col - 1] == '1' && !visited[row][col - 1]) {
            visited[row][col - 1l] = true;
            q.push({row, col - 1});
        }
        if (col < m - 1 && grid[row][col + 1] == '1' && !visited[row][col + 1]) {
            visited[row][col + 1] = true;
            q.push({row, col + 1});
        }
    }
}
int numIslands (vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int count;
    vector<vector<bool>> visited(n ,vector<bool> (m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && grid[i][j] == '1') {
                bfs(grid, visited, i, j);
                count++;
            }
        }
    }
    return count;
}

int main()
{
    
    return 0;
}
