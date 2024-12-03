#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// recursive 
int recursion(vector<int>& weights, vector<int>& values, int wt, int ind) {
    if (ind == 0) {
        if (weights[0] <= wt) {
            return values[0];
        }
        return 0;
    }
    int non_take = 0 + recursion(weights, values, wt, ind - 1);
    int take = INT_MIN;
    if (weights[ind] <= wt)
        take = values[ind] + recursion(weights, values, wt - weights[ind], ind - 1);
    return max(take, non_take);
}

// memoization
int memoization(vector<int>& weights, vector<int>& values, int wt, int ind, vector<vector<int>>& dp) {
    if (ind == 0) {
        if (weights[0] <= wt) {
            return values[0];
        }
        return 0;
    }
    if (dp[ind][wt] != -1) return dp[ind][wt];

    int non_take = 0 + memoization(weights, values, wt, ind - 1, dp);
    int take = INT_MIN;
    if (weights[ind] <= wt)
        take = values[ind] + memoization(weights, values, wt - weights[ind], ind - 1, dp);
    return dp[ind][wt] = max(take, non_take);
}

// tabulation
int tabulation(vector<int>& weights, vector<int>& values, int wt) {
    int n = weights.size();
    vector<vector<int>> dp (n, vector<int> (wt + 1, 0));
    for (int i = 0; i <= wt; i++) {
        if (weights[0] <= i) {
            dp[0][i] = values[0];
        }
    }

    for (int i = 1; i < n; i++) {
        for (int w = 0; w <= wt; w++) {
            int not_take = 0 + dp[i-1][w];
            int take = INT_MIN;
            if (w >= weights[i]) {
                take = values[i] + dp[i-1][w - weights[i]];
            }
            dp[i][w] = max(not_take, take);
        }
    }
    return dp[n-1][wt];
}

// space optimisation
int space_optimisation(vector<int>& weights, vector<int>& values, int wt) {
    int n = weights.size();
    vector<int> dp(wt + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int w = wt; w >= 0; w--) {
            int not_take = dp[w];
            int take = INT_MIN;
            if (w >= weights[i]) {
                take = values[i] + dp[w - weights[i]];
            }
            dp[w] = max(not_take, take);
        }
            for (int num : dp) cout << num << " ";
            cout << endl;
    }
    return dp[wt];
}
 
int main()
{
    vector<int> weights = {3, 4, 6};
    vector<int> values = {30, 50, 60};
    int wt = 6;
    int n = weights.size();
    // cout << recursion(weights, values, wt, n - 1) << endl;
    vector<vector<int>> dp (n, vector<int> (wt + 1, -1));
    cout << memoization(weights, values, wt, n - 1, dp) << endl;
    cout << tabulation(weights, values, wt) << endl;
    cout << space_optimisation(weights, values, wt);
    return 0;
}