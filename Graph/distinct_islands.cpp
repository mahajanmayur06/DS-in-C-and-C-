#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j, set<vector<pair<int, int>>>& set) {
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;
    vector<pair<int, int>> pairs;
    int delRows[] = {-1, 0, 1, 0};
    int delCols[] = {0, -1, 0, 1};
    
    q.push({i, j});
    visited[i][j] = true;
    pairs.push_back({0, 0});

    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nrow = row + delRows[k];
            int ncol = col + delCols[k];
            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !visited[nrow][ncol] && grid[nrow][ncol] == 1) {
                visited[nrow][ncol] = true;
                q.push({nrow, ncol});
                pairs.push_back({nrow - i, ncol - j}); 
            }
        }
    }
    set.insert(pairs); 
}

int numIslands(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    set<vector<pair<int, int>>> set;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && grid[i][j] == 1) {
                bfs(grid, visited, i, j, set);
            }
        }
    }

    for (auto& it : set) {
        cout << "set ";
        for (auto& v : it) {
            cout << "(" << v.first << ", " << v.second << ") ";
        }
        cout << endl;
    }

    return set.size(); 
}
int main()
{
    vector<vector<int>> matrix = {
        {1, 1, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 1, 1},
        {1, 1, 0, 0, 1}
    };
    cout << "ans " << numIslands(matrix) << endl;
    return 0;
}
