#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int frog_jump(vector<int>& arr, vector<int>& dp, int i, int jumps) {
    if (i == 0) return 0;
    if (dp[i] != -1) return dp[i];
    int steps = INT_MAX;
    for (int k = 0; k < jumps; k++) {
        if (i - k >= 0) {
            int jump = frog_jump(arr,  dp, i - k,jumps) + abs(arr[i] - arr[i - k]);
            steps = min(jump, steps);
        }
    }
    dp[i] = steps;
    return dp[i];
}

int frog_jump_tab(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> dp(n, 0);
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        int steps = INT_MAX;
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                int jump = dp[i - j] + abs(arr[i] - arr[i - j]);
                steps = min(jump, steps);
            }
        }
        dp[i] = steps;
    }
    return dp[n - 1];
}
int main()
{
    vector<int> dp;
    dp[0] = 0;
    return 0;
}