#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// using recursion
bool recursion (vector<int>& nums, int target, int i){
    if (target == 0) return true;
    if (i == 0) return nums[0] == target;
    bool not_take = recursion(nums, target, i - 1);
    bool take = false;
    if (nums[i] <= target)
        take = recursion(nums, target - nums[i], i - 1);
    return not_take || take;
}

// using memoization
bool memoization(vector<int>& nums, int target, int i, vector<vector<int>>& dp) {
    if (target == 0) return true;
    if (i == 0) {
        if (nums[i] == target) {
            dp[i][target] = true;
            return true;
        }
        else {
            dp[i][target] = false;
            return false;
        }
    }
    if (dp[i][target] != -1) {
        return dp[i][target];
    }
    bool not_take = recursion(nums, target, i - 1);
    bool take = false;
    if (nums[i] <= target)
        take = recursion(nums, target - nums[i], i - 1);
    return not_take || take;
}

// using tabulation


// using space opimisation
bool space_optimsation(vector<int>& nums, int target) {
    vector<bool> dp(target + 1, false);
    dp[0] = true;
    if (nums[0] <= target) {
        dp[nums[0]] = true;
    }

    for (int i = 1; i < nums.size(); i++) {
        vector<bool> temp(target + 1, false);
        temp[0] = true; 

        for (int j = 0; j <= target; j++) {
            bool non_take = dp[j];
            bool take = false;
            if (j >= nums[i]) {
                take = dp[j - nums[i]];
            }
            temp[j] = take || non_take; 
        }
        dp = temp; 
    }

    return dp[target];
}

int main()
{
    vector<int> nums = {2, 4, 5, 1, 3};
    int n = nums.size();
    int target = accumulate(nums.begin(), nums.end(), 0) / 2;
    if (target % 2 == 1) return false;
    bool ans = recursion(nums, target, n - 1);
    // vector<bool> dp (target + 1, false);
    vector<vector<int>> dp(n + 1, vector<int> (target, -1));
    cout << memoization(nums, target, n - 1, dp);
    cout << space_optimsation(nums, target);
    // cout << boolalpha << ans;
    return 0;
}