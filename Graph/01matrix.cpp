#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findDistance(vector<vector<int>>& mat, int i, int j) {
    int n = mat.size();
    int m = mat[0].size();
    int delRows[] = {-1, 0, 1, 0};
    int delCols[] = {0, 1, 0, -1};
    vector<vector<bool>> visited(n, vector<bool> (m ,false));
    queue<pair<pair<int, int>, int>> q;
    q.push({{i, j}, 0});
    while (!q.empty())
    {
        auto front = q.front();
        q.pop();
        int x = front.first.first;
        int y = front.first.second;
        int dist = front.second;
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int nrow = x + delRows[i];
            int ncol = y + delCols[i];
            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m) {
                if (mat[nrow][ncol] == 0) 
                    return dist + 1;
                if (!visited[nrow][ncol]) {
                    q.push({{nrow, ncol}, dist + 1});
                }
            }
        }
    }
    return 0;
}

vector<vector<int>> updateMatrix (vector<vector<int>>& mat) {
    vector<vector<int>> ans = mat;
    int n = mat.size();
    int m = mat[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 0) ans[i][j] = 0;
            else {
                ans[i][j] = findDistance(mat, i, j);
            }
        }
    }
    return ans;
}

int main()
{
    
    return 0;
}