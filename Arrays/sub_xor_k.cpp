#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Brute Force approach and Better approach - O(n^2) Time complexity
int bruteforce(vector<int>& arr, int k){
    int count = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int x = 0;
        for (int j = i; j < n; j++) {
            x ^= arr[j];
            if (x == k) count++;
        }
    }
    return count;
}

// optimized optimal approach
int subarraysWithXork(vector<int> arr, int k) {
    unordered_map<int, int> map;
    int count = 0;
    int xr = 0;
    map[0] = 1;
    for (int i = 0; i < arr.size(); i++) {
        xr ^= arr[i];

        int x = xr ^ k;
        count += map[x];
        map[xr]++;
    }
    return count;
}

int main()
{
    vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;
    cout << bruteforce(arr, k) << endl;
    cout << subarraysWithXork(arr, k) << endl;
    return 0;
}