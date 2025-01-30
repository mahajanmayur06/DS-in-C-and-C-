#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// recursion
int recursion(vector<int>& coins, int amount, int i) {
    if (i == 0) {
        if (amount % coins[0] == 0) return 1;
        return 0;
    }
    int not_take = recursion(coins, amount, i - 1);
    int take = 0;
    if (coins[i] <= amount) {
        take = recursion(coins, amount - coins[i], i);
    }
    return take + not_take;
}

// tabulation
int tabulation(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int> (amount + 1, 0));
    for (int i = 0; i <= amount; i++) {
        if (i % coins[0] == 0) 
            dp[0][i]  = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int t = 0; t <= amount; t++) {
            int not_take = dp[i-1][t];
            int take = 0;
            if (coins[i] <= t) {
                take = dp[i][t-coins[i]];
            }
            dp[i][t] = take + not_take;
        }
    }
    return dp[n-1][amount];
}

// space optmisation
int space_opt(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int t = 0; t <= amount; t++) {
            if (coins[i] <= t) {
                dp[t] += dp[t - coins[i]];
            }
        }
    }
    return dp[amount];
}

int main()
{
    vector<int> coins = {1,2,5,7};
    int amount = 15;
    int n = coins.size();
    // cout << recursion(coins, amount, n - 1);
    cout << tabulation(coins, amount) << endl;
    return 0;
}