#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void findSubsets(int ind, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans)
{
    ans.push_back(ds);
    for (int i = ind; i < nums.size(); i++)
    {
        if (i != ind && nums[i] == nums[i - 1])
            continue;
        ds.push_back(nums[i]);
        findSubsets(i + 1, nums, ds, ans);
        ds.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> ds;
    sort(nums.begin(), nums.end());
    findSubsets(0, nums, ds, ans);
    return ans;
}
int main()
{
    vector<int> nums = {1, 2, 2, 2, 3, 3};
    vector<vector<int>> ans = subsetsWithDup(nums);
    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}