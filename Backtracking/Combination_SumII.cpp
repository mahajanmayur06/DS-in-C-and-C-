#include <iostream>
#include <vector>
#include <algorithm>
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
    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }

    for (int i = ind; i < arr.size(); i++)
    {
        if (i > ind && arr[i] == arr[i - 1])
            continue;

        if (arr[i] <= target)
        {
            ds.push_back(arr[i]);
            findCombinations(i + 1, target - arr[i], arr, ans, ds);
            ds.pop_back();
        }
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> ds;
    sort(candidates.begin(), candidates.end());
    findCombinations(0, target, candidates, ans, ds);
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> set;
    set.resize(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> set[i];
    }

    int sum;
    cout << "Enter the target sum: ";
    cin >> sum;

    vector<vector<int>> ans = combinationSum(set, sum);
    for (int i = 0; i < ans.size(); i++)
    {
        printVector(ans[i]);
    }
    return 0;
}
