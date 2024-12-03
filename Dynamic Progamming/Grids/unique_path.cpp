#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// recursion
int recursion(int i, int j) {
    if (i == 0 && j == 0) {
        return 1;
    }
    if (i < 0 || j < 0) return 0;
    int up = recursion(i - 1, j);
    int left = recursion(i, j - 1);
    return left + up;
}

// memoization
int memoization(int i, int j, vector<vector<int>>& dp) {
    if (i == 0 && j == 0) {
        return 1;
    }
    if (i < 0 || j < 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int up = memoization(i - 1, j, dp);
    int left = memoization(i, j - 1, dp);
    
    dp[i][j] = left + up;
    return dp[i][j];
}

// tabulation
int tabulation(int n, int m) {
    vector<vector<int>> dp(n, vector<int> (m, 0));
    dp[0][0] = 1;
    // for (int i = 1; i < n; i++) dp[i][0] = 1;
    // for (int j = 1; j < m; j++) dp[0][j] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[n-1][m-1];
}

int main()
{
    int n = 3, m = 4;
    // cout << recursion(n - 1, m - 1) << endl;
    // vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
    // cout << memoization(n - 1, m - 1, dp) << endl;
    cout << tabulation(n, m);
    return 0;
}