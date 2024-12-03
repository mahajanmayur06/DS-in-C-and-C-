#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// 1e9 = INT_MAX

// tabulation
int tabulation(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int> (amount + 1, 1e9));
    for (int i = 0; i <= amount; i++) {
        if (i % coins[0] == 0) {
            dp[0][i] = i / coins[0];
        }
    }
    for (int i = 1; i < n; i++) {
        for (int t = 0; t <= amount; t++) {
            int not_take = dp[i-1][t];
            int take = 1e9;
            if (coins[i] <= t) {
                take = 1 + dp[i][t-coins[i]];
            }
            dp[i][t] = min(take, not_take);
        }
    }
    if (dp[n-1][amount] == 1e9) {
        return -1;
    }
    return dp[n-1][amount];
}

int main()
{
    vector<int> coins = {1,2,5,7};
    int amount = 15;
    cout << tabulation(coins, amount) << endl;
    return 0;
}