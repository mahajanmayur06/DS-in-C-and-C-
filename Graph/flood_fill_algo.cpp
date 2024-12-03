#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void bfs (vector<vector<int>>& image, int sr, int sc, int color) {
    int n = image.size();
    int m = image[0].size();
    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, +1, 0, -1};

    int val = image[sr][sc];
    queue<pair<int, int>> q;
    q.push({sr, sc});
    while (!q.empty()) {
        auto front = q.front();
        int x = front.first;
        int y = front.second;
        image[x][y] = color;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nrow = x + delRow[i];
            int ncol = y + delCol[i];
            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && image[nrow][ncol] == val) {
                q.push({nrow, ncol});
            }
        }
    }
}

// int delRow[] = {-1, 0, +1, 0};
// int delCol[] = {0, +1, 0, -1};
// for (int i = 0; i < 4; i++) {
//     int nrow = x + delRow[i];
//     int ncol = y + delCol[i];
//     if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m) {
//         q.push({nrow, ncol});
//     }
// }


// for (int i = -1; i <= 1; i++) {
//     nrow = row + i;
//     ncol = col + i;
//     if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m) {
//         q.push({nrow, ncol});
//     }
// }

void dfs (vector<vector<int>>& image, int r, int c, int color, int newColor) {
    if (image[r][c] == color) {
        image[r][c] = newColor;
        if (r > 0) {
            dfs(image, r - 1, c, color, newColor);
        }
        if (c > 0) {
            dfs(image, r, c - 1, color, newColor);
        }
        if (r + 1 < image.size()) {
            dfs(image, r + 1, c, color, newColor);
        }
        if (c + 1 < image[0].size()) {
            dfs(image, r, c + 1, color, newColor);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    if (image[sr][sc] == color) return image;
    bfs(image, sr, sc, color);
    return image;
}

int main()
{
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    vector<vector<int>> copy = image;
    int sr = 1, sc = 1, color = 2;
    if (image[sr][sc] != color) {
        bfs(copy, sr, sc, color);
    }
    for (auto it : copy) {
        for (int num : it) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}