#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> res;

// recursion
void permute (vector<int>& nums, int i) {
    if (i >= nums.size()) {
        res.push_back(nums);
        return;
    }
    for (int k = i; k < nums.size(); k++) {
        swap(nums[k], nums[i]);
        permute(nums, i + 1);
        swap(nums[k], nums[i]);
    }
}

// backtracking

int main()
{
    vector<int> nums = {1, 2, 3};
    permute(nums, 0);
    for (auto& itr : res) {
        for (int num : itr) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}