#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> arr = {{20,11},{8,10}, {1,3},{5,1}};
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i][0] << " " << arr[i][1] << endl;
    }
    return 0;
}