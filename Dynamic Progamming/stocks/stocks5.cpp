#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int recursion(vector<int>& stocks, int buy, int i, int fee) {
    if (i >= stocks.size()) {
        return 0;
    }
    int op1, op2;
    if (buy == 1) {
        op1 = 0 + recursion(stocks, 1, i + 1, fee);
        op2 = stocks[i] + recursion(stocks, 0, i + 1, fee) - fee;
    }
    else {
        op1 = 0 + recursion(stocks, 0, i + 1, fee);
        op2 = -stocks[i] + recursion(stocks, 1, i + 1 , fee);
    }
    return max(op1, op2);
}

int memoization (vector<int>& stocks, int buy, int i, vector<vector<int>>& dp, int fee) {
    if (i >= stocks.size()) {
        return 0;
    }
    if (dp[i][buy] != -1) return dp[i][buy];
    int op1, op2;
    if (buy == 1) {
        op1 = 0 + memoization(stocks, 1, i + 1, dp, fee);
        op2 = stocks[i] + memoization(stocks, 0, i + 1, dp, fee) - fee;
    }
    else {
        op1 = 0 + memoization(stocks, 0, i + 1, dp, fee);
        op2 = -stocks[i] + memoization(stocks, 1, i + 1, dp, fee);
    }
    return dp[i][buy] = max(op1, op2);
}

int tabulation (vector<int>& stocks) {
    int n = stocks.size();
    vector<vector<int>> dp (n + 2, vector<int> (2, 0));
    dp[n][0] = dp[n][1] = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int buy = 0; buy <= 1; buy++) {
            int profit;
            if (buy == 1) {
                profit = max(dp[i + 1][1], dp[i + 2][0] + stocks[i]);
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
    
    return 0;
}