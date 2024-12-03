#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int calculator(vector<int>& nums, int start, int target, int ops) {
    if (start <= 0 || start >= 2 * target + 1) {
        return INT_MAX;
    }
    if (start == target) {
        return ops;
    }
    
    if (nums[start] != 0 && nums[start] <= ops) {
        return INT_MAX;
    }        
    nums[start] = ops;
    
    int op1 = calculator(nums, start - 1, target, ops + 1);
    int op2 = calculator(nums, start * 2, target, ops + 1);
    
    return min(op1, op2);
}

int brokenCalc(int startValue, int target) {
    if (startValue >= target) {
        return startValue - target;
    }

    vector<int> nums(2 * target + 1, 0);
    int res = calculator(nums, startValue, target, 0);
    return res;
}

int main()
{
    cout << brokenCalc(1, 1000);
    return 0;
}