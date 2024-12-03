#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited = grid; 
    queue<pair<pair<int, int>, int>> q;  
    int time = 0;
    int freshOranges = 0; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 2) {
                q.push({{i, j}, 0});
            }
            if (grid[i][j] == 1) {
                freshOranges++;
            }
        }
    }

    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, +1, 0, -1};
    int rottenCount = 0; 

    while (!q.empty()) {
        auto front = q.front();
        int x = front.first.first, y = front.first.second;
        int t = front.second;
        q.pop();
        time = max(time, t);  
        for (int i = 0; i < 4; i++) {
            int nrow = x + delRow[i];
            int ncol = y + delCol[i];
            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && visited[nrow][ncol] == 1) {
                q.push({{nrow, ncol}, t + 1});
                visited[nrow][ncol] = 2;
                rottenCount++;
            }
        }
    }

    return (freshOranges == rottenCount) ? time : -1;
}

int main()
{
    
    return 0;
}