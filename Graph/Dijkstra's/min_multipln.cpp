#include <bits/stdc++.h>
using namespace std;

// problem was thinking of Mod array which will store distance of multiplication from start number
int func (vector<int>& arr, int start, int end) {
    int MOD = 1e5;
    queue<pair<int, int>> q;
    q.push({0, start});
    vector<int> dist(MOD - 1, INT_MAX);
    dist[start] = 0;
    while (!q.empty()) {
        int steps = q.front().first;
        int num = q.front().second;
        q.pop();
        if (num == end) return steps;
        for (int i = 0; i < arr.size(); i++) {
            int newNum = (num * arr[i]) % MOD;
            if (dist[newNum] > steps + 1) {
                dist[newNum] = steps + 1;
                q.push({dist[newNum], newNum});
            }
        }
    }
    return -1;
}

// TC : O(N * 100000) hypothetical scenario
int main()
{
    
    return 0;
}