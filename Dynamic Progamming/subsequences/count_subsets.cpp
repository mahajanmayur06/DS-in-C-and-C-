#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// nums[i] >= 1

// To handle cases of zero, we must multipy ans with pow(2, no_of_zeroes)
// {0,0,1} tar = 1 --> {1}, {0,1} {0,1} {0,0,1}

// using recursion
int recursion (vector<int>& nums, int sum, int i){
    if (sum < 0) return 0;
    if (sum == 0) return 1;
    if (i == 0) {
        if (nums[0] == sum){
            return 1;
        }
        return 0;
    }
    int not_take = recursion(nums, sum, i - 1);
    int take = 0;
    if (nums[i] <= sum)
        take = recursion(nums, sum - nums[i], i - 1);
    return take + not_take;
}

// using memoization
int memoization(vector<int>& nums, int sum, int i, vector<vector<int>>& dp) {
    if (sum < 0) return 0;
    if (sum == 0) return 1;
    if (i == 0) {
        if (nums[0] == sum){
            return 1;
        }
        return 0;
    }
    if (dp[i][sum] != -1) return dp[i][sum];
    int not_take = recursion(nums, sum, i - 1);
    int take = 0;
    if (nums[i] <= sum)
        take = recursion(nums, sum - nums[i], i - 1);
    dp[i][sum] = take + not_take;
    return dp[i][sum];
}

// using tabulation
int tabulation(vector<int>& nums, int sum) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int> (sum + 1, 0));
    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }
    if (nums[0] <= sum) {
        dp[0][nums[0]] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int t = 1; t <= sum; t++) {
            int not_take = dp[i-1][t];
            int take = 0;
            if (nums[i] <= t) {
                take = dp[i - 1][t - nums[i]];
            }
            dp[i][t] = take + not_take;
        }
    }
    return dp[n-1][sum];
}

// space optmisation
int space_optimisation(vector<int>& nums, int sum) {
    int n = nums.size();
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int tar = sum; tar >= 0; tar--) {
            int not_take = dp[tar];
            int take = 0;
            if (tar >= nums[i]) {
                take = dp[tar - nums[i]];
            }
            dp[tar] = take + not_take;
        }
        for (int num : dp) cout << num << " ";
        cout << endl;
    }
    return dp[sum];
}

int main()
{
    // vector<int> nums = {1,2,3,4,5,6};
    // int sum = 8;
    vector<int> nums = {4,3,5,3,2};
    int sum = 8;

    int n = nums.size();
    int ans = recursion(nums, sum, n - 1);
    cout << ans << endl;
    // vector<int> dp (sum + 1, false);
    vector<vector<int>> dp(n, vector<int> (sum + 1, -1));
    cout << memoization(nums, sum, n - 1, dp) << endl;
    cout << tabulation(nums, sum) << endl;
    cout << space_optimisation(nums, sum);
    return 0;
}