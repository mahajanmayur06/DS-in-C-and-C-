#include <bits/stdc++.h>
using namespace std;

// build the segment tree
void build (vector<int>& arr, vector<int>& seg,int i, int left, int right) {
    if (left == right) {
        seg[i] = arr[left];
        return;
    }
    int mid = left + (right - left) / 2;
    build(arr, seg, 2 * i + 1, left, mid);
    build(arr, seg, 2 * i + 2, mid + 1, right);
    seg[i] = max(seg[2 * i + 1], seg[2 * i + 2]);
}

// query the maximum value in the range [l, r]
int query (vector<int>& seg, int i, int low, int high, int l, int r) {
    if (low >= l && high <= r) {
        return seg[i];
    }
    if (high < l || low > r) {
        return INT_MIN;
    }
    int mid = low + (high - low) / 2;
    int leftMax = query(seg, 2 * i + 1, low, mid, l, r);
    int rightMax = query(seg, 2 * i + 2, mid + 1, high, l, r);
    return max(leftMax, rightMax);
}

int main()
{
    vector<int> arr = {10, 52, 1, 45, 100, 13, 3};
    int n = arr.size();   
    vector<int> seg(4 * n, INT_MIN);
    build(arr, seg, 0, 0, n - 1);
    cout << query(seg, 0, 0, n - 1, 1, 3) << endl; 
    cout << query(seg, 0, 0, n - 1, 0, 5) << endl; 
    return 0;
}