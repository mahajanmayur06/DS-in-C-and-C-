#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int coinChange(vector<int> &coins, int amount) {
    if (amount == 0)
        return 0;

    sort(coins.begin(), coins.end());
    if (coins[0] > amount)
        return -1;

    vector<int> dp(amount + 1, -1);

    for (int i = 0; i < coins.size(); i++) {
        if (coins[i] <= amount)
            dp[coins[i]] = 1;
    }

    for (int i = coins[0] + 1; i <= amount; i++) {
        if (dp[i] == 1)
            continue;

        int min = INT16_MAX;

        for (int j = 0; j < coins.size(); j++) {
            int flag = i - coins[j];
            if (flag > 0 && dp[flag] != -1) {
                int newMin = dp[flag] + 1;
                if (newMin < min)
                    min = newMin;
            }
        }

        if (min == INT16_MAX)
            dp[i] = -1;
        else
            dp[i] = min;
    }
    return dp[amount];
}

int main()
{
    
    return 0;
}