#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// using recursion
int recursion(vector<int>& height, vector<int>& dp, int i) {
    int n = height.size();
    if (i == 0) return 0;
    if (dp[i] != -1) return dp[i];
    int left, right = INT_MAX;
    left = recursion(height, dp, i - 1) + abs(height[i] - height[i - 1]);
    if (i > 1)
        right = recursion(height, dp, i - 2) + abs(height[i] - height[i - 2]);
    dp[i] = min(left, right);
    return dp[i];
}

// using memoization
int memoization(vector<int>& height, vector<int>& dp, int i) {
    int n = height.size();
    if (i == 0) return 0;

    int left, right = INT_MAX;
    if (dp[i - 1] != -1)
        left = memoization(height, dp, i - 1) + abs(height[i] - height[i - 1]);
    else
        left = dp[i - 1] + abs(height[i] - height[i - 1]);
    if (i > 1) {
        if (dp[i - 2] != -1)
            right = memoization(height, dp, i - 2) + abs(height[i] - height[i - 2]);
        else
            right = dp[i - 2] + abs(height[i] - height[i - 2]);
    }
    dp[i] = min(left, right);
    return dp[i];
}

// using tabulation
int frog_jump(vector<int>& height) {
    int n = height.size();
    vector<int> dp (n, -1);
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1] + max(height[i - 1], height[i]);
    }
    return dp[n - 1];
}

int main()
{
    vector<int> height = {10, 40, 50, 10, 20};
    int n = height.size();
    vector<int> dp(n, -1);
    int ans = memoization(height, dp, n - 1);
    cout << ans;
    return 0;
}