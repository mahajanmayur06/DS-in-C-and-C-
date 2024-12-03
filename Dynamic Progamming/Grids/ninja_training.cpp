#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Using recursion 
int recursionUtil(int i, int j, vector<vector<int>>& points) {
    if (i == 0) return points[0][j];
    int skill = 0;
    for (int k = 0; k < 3; k++) {
        if (k != j) {
            skill = max(skill, recursionUtil(i - 1, k, points));
        }
    }
    return skill + points[i][j];
}

int recursion(vector<vector<int>> &points)
{
    // Write your code here.
    int n = points.size();
    int ans = 0;
    for (int j = 0; j < 3; j++) {
        ans = max(ans, recursionUtil(n - 1, j, points));
    }
    return ans;
}

// using tabulation
int tabulation(vector<vector<int>>& points) {
    int n = points.size();
    vector<vector<int>> dp(n, vector<int> (4, 0));
    
}

int main()
{
    vector<vector<int>> arr = {{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};
    // vector<vector<int>> arr = {{2, 1, 3}, {3, 4, 6}, {10, 1, 6}, {8, 3, 7}};
    cout << recursion(arr) << endl;
    return 0;
}