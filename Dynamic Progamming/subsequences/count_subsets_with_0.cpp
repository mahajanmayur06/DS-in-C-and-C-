#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// nums[i] >= 0

// To handle cases of zero, we must multipy ans with pow(2, no_of_zeroes)
// {0,0,1} tar = 1 --> {1}, {0,1} {0,1} {0,0,1}

// using recursion
int recursion (vector<int>& nums, int sum, int i){
    if (i == 0) {
        if (sum == 0 && nums[0] == 0) {
            return 2;
        }
        if (nums[0] == sum || sum == 0){
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
    if (i == 0) {
        if (sum == 0 && nums[0] == 0) {
            return 2;
        }
        if (nums[0] == sum || sum == 0){
            return 1;
        }
        return 0;
    }
    if (dp[i][sum] != -1) return dp[i][sum];
    int not_take = memoization(nums, sum, i - 1, dp);
    int take = 0;
    if (nums[i] <= sum)
        take = memoization(nums, sum - nums[i], i - 1, dp);
    dp[i][sum] = take + not_take;
    return dp[i][sum];
}

// using tabulation
int tabulation(vector<int>& nums, int sum) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int> (sum + 1, 0));

    for (int i = 0; i <= sum; i++) {
        if (i == 0 && nums[0] == 0) {
            dp[0][i] = 2;  
        } else if (i == 0 || nums[0] == i) {
            dp[0][i] = 1; 
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= sum; j++) {
            int not_take = dp[i - 1][j];  
            int take = 0;
            if (nums[i] <= j) {
                take = dp[i - 1][j - nums[i]]; 
            }
            dp[i][j] = take + not_take;  
        }
    }

    return dp[n - 1][sum];
}

int main()
{
    // vector<int> nums = {1,2,3,4,5,6};
    // int sum = 8;
    vector<int> nums = {0, 1, 3};
    int sum = 4;

    int n = nums.size();
    int ans = recursion(nums, sum, n - 1);
    cout << ans << endl;
    vector<vector<int>> dp(n , vector<int> (sum + 1, -1));
    // cout << memoization(nums, sum, n - 1, dp) << endl;
    cout << tabulation(nums, sum);

    return 0;
}