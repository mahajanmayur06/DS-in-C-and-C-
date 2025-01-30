#include <bits/stdc++.h>
using namespace std;

// build the segment tree
void build (vector<int>& arr, vector<int>& seg, int i, int left, int right) {
    if (left == right) {
        seg[i] = arr[left];
        return;
    }
    int mid = left + (right - left) / 2;    
    build(arr, seg, 2 * i + 1, left, mid);
    build(arr, seg, 2 * i + 2, mid + 1, right);
    seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
}

// increase the value of arr[index] by val
void queryRangeUpdate (vector<int>& seg, vector<int>& lazy, int i, int low, int high, int l, int r, int val) {
    if (lazy[i] != 0) {
        seg[i] += (high - low + 1) * lazy[i];
        if (low != high) {
            lazy[2 * i + 1] += lazy[i];
            lazy[2 * i + 2] += lazy[i];
        }
        lazy[i] = 0;
    }
    if (r < low || l > high || low > high) {
        return;
    }

    if (low >= l && high <= r) {
        seg[i] += (high - low + 1) * val;
        if (low != high) {
            lazy[2 * i + 1] += val;
            lazy[2 * i + 2] += val;
        }
        return;
    }

    int mid = low + (high - low) / 2;
    queryRangeUpdate(seg, lazy, 2 * i + 1, low, mid, l, r, val);
    queryRangeUpdate(seg, lazy, 2 * i + 2, mid + 1, high, l, r, val);
    seg[i] = seg[2 * i + 1] + seg[2 * i + 2];   
}

// query the sum of the values in the range [l, r]
int querySum (vector<int>& seg, vector<int>& lazy, int i, int low, int high, int l, int r, int val) {
    if (lazy[i] != 0) {
        seg[i] += (high - low + 1) * lazy[i];
        if (low != high) {
            lazy[2 * i + 1] += lazy[i];
            lazy[2 * i + 2] += lazy[i];
        }
        lazy[i] = 0;
    }
    if (r < low || l > high || low > high) {
        return 0;
    }

    if (low >= l && high <= r) {
        return seg[i];
    }

    int mid = low + (high - low) / 2;
    int leftSum = querySum(seg, lazy, 2 * i + 1, low, mid, l, r, val);
    int rightSum =  querySum(seg, lazy, 2 * i + 2, mid + 1, high, l, r, val);
    return leftSum + rightSum; 
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int n = arr.size();
    vector<int> seg(4 * n, 0);
    vector<int> lazy(4 * n, 0);
    build (arr, seg, 0, 0, n - 1);
    cout << querySum(seg, lazy, 0, 0, n - 1, 1, 3, 0) << endl; 
    queryRangeUpdate(seg, lazy, 0, 0, n - 1, 1, 3, 3);
    cout << querySum(seg, lazy, 0, 0, n - 1, 1, 3, 0) << endl;
    return 0;
}