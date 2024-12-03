#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> &v)
{
    cout << "[";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
        if (i != v.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}

void findCombinations(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
{
    if (ind == arr.size())
    {
        if (target == 0)
            ans.push_back(ds);
        return;
    }

    if (arr[ind] <= target)
    {
        ds.push_back(arr[ind]);
        findCombinations(ind, target - arr[ind], arr, ans, ds);
        ds.pop_back();
    }

    findCombinations(ind + 1, target, arr, ans, ds);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> ds;
    findCombinations(0, target, candidates, ans, ds);
    return ans;
}

int main()
{
    vector<int> data = {1, 2, 3, 9, 5, 6, 8};
    vector<vector<int>> ans = combinationSum(data, 5);
    for (int i = 0; i < ans.size(); i++)
        printVector(ans[i]);
    
    return 0;
}