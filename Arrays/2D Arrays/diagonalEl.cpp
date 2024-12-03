#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void findDiagonalOrder(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<int> ans;
    int k = m * n;
    int i = 0;
    int j = 0;
    bool dir = true;
    while (k > 0) {
        ans.push_back(mat[i][j]);
        cout << ans[ans.size() - 1] << " ";
        if (dir){
            if (j == m - 1) {
                i++;
                dir = false;
            }
            else if (i == 0) {
                j++;
                dir = false;
            }
            else {
                i--;
                j++;
            }
        }
        else {
            if (i == n - 1){
                j++;
                dir = true;
            }
            else if (j == 0){
                i++;
                dir = true;
            }
            else{
                i++;
                j--;
            }
        }
        k--;
    }
    // return ans;
}

int main() {
    vector<vector<int>> mat = {{1,2,3,4}, {5,6,7,8},{9,10,11,12},{13,14,15,16}};
    findDiagonalOrder(mat);
    return 0;
}