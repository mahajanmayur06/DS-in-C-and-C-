#include <bits/stdc++.h>
using namespace std;

int findNum (vector<int>& nums, int x) {
    int n = nums.size();
    int left = 0, right = n - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == x) {
            return mid;
        }
        else if (nums[mid] < x) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return nums[left] == x ? left : -1;
}

int main() {
    
    return 0;
}