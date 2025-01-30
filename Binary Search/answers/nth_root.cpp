#include <bits/stdc++.h>
using namespace std;

int func (int mid, int n, int k) {
    long long ans = 1;
    for (int i = 0; i < n; i++) {
        ans *= mid;
        if (ans > k) return 2;
    }
    if (ans == k) return 1;
    return 0;
}
int findNthRoot (int num, int k) {
    int left = 1, right = num;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int midNum = func(mid, k, num);
        if (midNum == 1) 
            return mid;
        else if (midNum == 0) {
            left = mid + 1;
        }
        else 
            right = mid - 1;
    }
    return -1;
}
int main() {
    
    return 0;
}