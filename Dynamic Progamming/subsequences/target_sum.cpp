#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// recursion
int recursion(vector<int>& nums, int target, int ind) {
    if (ind == 0) {
        if (nums[0] == 0 && target == 0) return 2; // To handle zeroes in it 
        if (target - nums[0] == 0) return 1;
        if (target + nums[0] == 0) return 1;
        return 0;
    }
    int pos = recursion(nums, target - nums[ind], ind - 1);
    int neg = recursion(nums, target + nums[ind], ind - 1);
    return pos + neg;
}

// tabulation
int tabulation(vector<int>& nums, int target) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    vector<vector<int>> dp(n, vector<int> (sum + 1, 0));
    
    
}

int main()
{
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    int n = nums.size();
    cout << recursion(nums, target, n - 1);
    return 0;
}