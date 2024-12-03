#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

// SC : O(n^2)
int kthLargest(vector<int> &arr, int k) {
    // code here
    int n = arr.size();
    priority_queue<long long> pq;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j]; 
            pq.push(sum); 
        }
    }
    for (int i = 0; i < k - 1; i++) pq.pop();
    return pq.top();
}

// using min heap -> here, kth largest element will be at the top (in array of k element kth largest will be arr[0] which is top of mean heap)
// all the min elements of heap will be children of heap
// SC : O(k)

int kthLargestSum(vector<int> &arr, int k) {
    int n = arr.size();
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j]; 
            if (pq.size() < k) {
                pq.push(sum);
            } else if (sum > pq.top()) {
                pq.pop();
                pq.push(sum);
            }
        }
    }

    return pq.top();
}

int main()
{
    vector<int> nums = {2, 6, 4, 1};
    int k = 3;
    cout << kthLargest(nums, k) << endl;
    cout << kthLargestSum(nums, k);
    return 0;
}   