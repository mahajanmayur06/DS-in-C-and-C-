#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// int recursionUtil (vector<vector<int>>& matrix, int i, int j) {
//     if (i < 0 || j < 0) return 0;
    
// }

int tabulation (vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n + 1, vector<int> (m + 1));
    int ans =0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 1) {
                dp[i + 1][j + 1] = 1 + min({dp[i][j + 1], dp[i + 1][j], dp[i][j]});
                ans += dp[i + 1][j + 1];
            }
        }
    }
    return ans;
}

int main() {

} 