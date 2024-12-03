#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int recursion (vector<int>& stocks, int buy, int i) {
    if (i == stocks.size()) {
        return 0;
    }
    int op1, op2;
    if (buy == 1) {
        op1 = 0 + recursion(stocks, 1, i + 1);
        op2 = stocks[i] + recursion(stocks, 0, i + 1);
    }
    else {
        op1 = 0 + recursion(stocks, 0, i + 1);
        op2 = -stocks[i] + recursion(stocks, 1, i + 1);
    }
    return max(op1, op2);
}

// memoization
int memoization (vector<int>& stocks, int buy, int i, vector<vector<int>>& dp) {
    if (i == stocks.size()) {
        return 0;
    }
    if (dp[i][buy] != -1) return dp[i][buy];
    int op1, op2;
    if (buy == 1) {
        op1 = 0 + memoization(stocks, 1, i + 1, dp);
        op2 = stocks[i] + memoization(stocks, 0, i + 1, dp);
    }
    else {
        op1 = 0 + memoization(stocks, 0, i + 1, dp);
        op2 = -stocks[i] + memoization(stocks, 1, i + 1, dp);
    }
    return dp[i][buy] = max(op1, op2);
}

// tabulation
int tabulation (vector<int>& stocks) {
    int n = stocks.size();
    vector<vector<int>> dp (n + 1, vector<int> (2, 0));
    dp[n][0] = dp[n][1] = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int buy = 0; buy <= 1; buy++) {
            int profit;
            if (buy == 1) {
                profit = max(dp[i + 1][1], dp[i + 1][0] + stocks[i]);
            }
            else {
                profit = max(dp[i + 1][0], dp[i + 1][1] - stocks[i]) ;
            }
            dp[i][buy] = profit;
        }
    }
    return dp[0][0];
}

int main()
{
    vector<int> stocks = {7, 1, 5, 3, 6, 4};
    int n = stocks.size();
    cout << recursion(stocks, 0, 0);
    vector<vector<int>> dp (n, vector<int> (2, -1));
    return 0;
}