#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int stocks1(vector<int> stocks) {
    int n = stocks.size();
    int buy = stocks[0];
    int profit = 0;
    for (int i = 0; i < n; i++) {
        if (stocks[i] > buy) {
            profit = max(profit, stocks[i] - buy);
        }
        buy = min(stocks[i], buy);
    }
    return profit;
}
int main()
{
    
    return 0;
}