#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//  A B C D
// 0 1 2 3 4
//   i     j

int recursion (vector<int>& nums, int i, int j) {
    if (j - i == 0) {
        return 0;
    }
    int mul = INT_MAX;
    for (int k = i; k < j; k++) {
        int steps = nums[i - 1] * nums[k] * nums[j] + recursion(nums, i, k) + recursion(nums, k + 1, j);
        mul = min(steps, mul);
    }
    return mul;
}

int memoization (vector<int>& nums, int i, int j, vector<vector<int>>& dp) {
    if (j - i == 0) {
        return 0;
    }
    int mul = INT_MAX;
    if (dp[i][j] != -1) return dp[i][j];
    for (int k = i; k < j; k++) {
        int steps = nums[i - 1] * nums[k] * nums[j] + memoization(nums, i, k, dp) + memoization(nums, k + 1, j, dp);
        mul = min(steps, mul);
    }
    return dp[i][j] = mul;
}

// int tabulation (vector<int> & nums) {
//     int n = nums.size();
//     vector<vector<int>> dp(n, vector<int> (n, 0));
//     for (int i = 1; i < n ; i++) {
//         for (int j = i + 1; j < n; j++) {
//             dp[i][j] = INT_MAX;
//             for (int k = i; k < j; k++) {
//                 int steps = nums[i - 1] * nums[k] * nums[j] + dp[i][k] + dp[k + 1][j];
//                 dp[i][j] = min(dp[i][j], steps);
//             }
//         }
//     }
//     for (auto& it : dp) {
//         for (int num : it)
//             cout << num << " ";
//         cout << endl;
//     }
//     return dp[0][n - 1];
// }

int main() {
    vector<int> nums = {3,7,4,5};
    // vector<int> nums = {1,3,1,4,1,5};
    int n = nums.size();
    int ans = recursion(nums, 1, n - 1);
    vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
    cout << ans << endl;
    cout << memoization(nums, 1, n - 1, dp) << endl;
    // cout << tabulation(nums);
    return 0;
}