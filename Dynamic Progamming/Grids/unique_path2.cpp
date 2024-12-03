#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// recursion
int recursion(vector<vector<int>> &grid, int i, int j) {
    if (i == 0 && j == 0) {
        return 1;
    }
    if (i < 0 || j < 0 || grid[i][j] == 1) return 0;
    int up = recursion(grid, i - 1, j);
    int left = recursion(grid, i, j - 1);
    return left + up;
}

// memoization
int memoization(vector<vector<int>> &grid, int i, int j, vector<vector<int>>& dp) {
    if (i == 0 && j == 0) {
        return 1;
    }
    if (i < 0 || j < 0) return 0;
    if (grid[i][j] == 1) {
        dp[i][j] = 0;
        return 0;
    }
    if (dp[i][j] != -1) return dp[i][j];
    int up = memoization(grid, i - 1, j, dp);
    int left = memoization(grid, i, j - 1, dp);
    
    dp[i][j] = left + up;
    return dp[i][j];
}

// tabulation
int tabulation(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int> (m, 0));
    dp[0][0] = 1;
    for (int i = 1; i < n; i++) dp[i][0] = 1;
    for (int j = 1; j < m; j++) dp[0][j] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (grid[i][j])
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[n-1][m-1];
}

// space optimisation
int space_optimisation (vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<int> dp(m + 1, 0); // Here array should be of length grid[0]
    dp[1] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i - 1][j - 1] == 1)
                dp[j] = 0;
            else
                dp[j] = dp[j] + dp[j - 1];
        }
    }
    return dp[m];
}

int main()
{
    vector<vector<int>> grid;
    if (grid[0][0 || grid.back().back()]) {
        cout << 0; 
        return 0;
    }
    // cout << recursion(n - 1, m - 1) << endl;
    // vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
    // cout << memoization(n - 1, m - 1, dp) << endl;
    cout << tabulation(grid);
    return 0;
}