#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int recursion(vector<int>& nums, int i, int next) {
    if (i < 0) 
        return 0; 

    int op1 = INT_MIN;
    if (next > nums[i]) {
        op1 = 1 + recursion(nums, i - 1, nums[i]);
    }
    int op2 = recursion(nums, i - 1, next);
    
    return max(op1, op2);
}

int memoization (vector<int>& nums, int i, int next_ind, vector<vector<int>>& dp) {
    if (i < 0) 
        return 0; 

    if (dp[i][next_ind] != -1) return dp[i][next_ind];
    
    int op1 = INT_MIN;
    if (next_ind == nums.size() || nums[next_ind] > nums[i]) {
        op1 = 1 + memoization(nums, i - 1, i, dp);
    }
    int op2 = memoization(nums, i - 1, next_ind, dp);
    dp[i][next_ind] = max(op1, op2);
    return dp[i][next_ind];
}

int tabulation(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp (n , vector<int> (n + 1, 0));
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            int op1 = INT_MIN;
            if (nums[i] < nums[j] || j == n) {
                op1 = 1 + dp[i - 1][i];
            }
            int op2 = dp[i-1][j];
            dp[i][j] = max(op1, op2);
        }
    }
    return dp[n - 1][n];
}

// Space optimised using O(n) space
int space_opt(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n + 1, 1);
    int len = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        len = max(len, dp[i]);
    }
    return len;
}

// Binary search
int binary_search(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return 1; 

    vector<int> bin;
    bin.push_back(nums[0]);
    
    for (int i = 1; i < n; i++) {
        if (bin.back() < nums[i]) {
            bin.push_back(nums[i]);
        } else {
            int ind = lower_bound(bin.begin(), bin.end(), nums[i]) - bin.begin();
            bin[ind] = nums[i];
        }
    }
    
    return bin.size();
}
int main()
{
    // vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 38};
    vector<int> nums = {0,1,0,3,2,3};
    int n = nums.size();
    vector<vector<int>> dp (n , vector<int> (n + 1, -1));
    int ans  = memoization(nums, n - 1, n,  dp);
    for (auto &it : dp) {
        for (int num : it) cout << num << " ";
        cout << endl;
    }
    cout << "ans : " << ans << endl;
    return 0;
}