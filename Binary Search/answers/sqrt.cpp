#include <bits/stdc++.h>
using namespace std;

int findroot (int num ) {
    int left = 1, right = num;
    while (right >= left) {
        int mid = left + (right - left) / 2;
        if (mid * mid <= num) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return right;
}

int main() {
    
    return 0;
}