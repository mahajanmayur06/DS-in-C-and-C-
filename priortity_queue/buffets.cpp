#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int find(vector<int>& arr, int k) {
    int res = 0;
    priority_queue<int,greater<int>> pq(arr.begin(), arr.end()); 
    for (int i = 0; i < k; i++) {
        int front = pq.top();
        pq.pop();
        res += front;
        pq.push(front / 2); 
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << find(arr, k) << endl;
    }
    return 0;
}
