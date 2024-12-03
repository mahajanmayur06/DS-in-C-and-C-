#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int bouquets (vector<int>& nums, int day, int k) {
    int n = nums.size();
    int count = 0, bouq = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] > day) {
            bouq += count / k;
            count = 0;
        }
        else {
            count++;
        }
    }
    bouq += count / k;
    return bouq;
}

int mBouquets(vector<int>& nums, int m, int k) {
    int left = *min_element(nums.begin(), nums.end());
    int right = *max_element(nums.begin(), nums.end());
    while(left <= right) {
        int mid = (left + right) / 2;
        if (bouquets(nums, mid, k) >= m) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return left;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    int n = bloomDay.size();
    long long val = m * 1ll * k * 1ll;
    if (n < val) return -1;
    return mBouquets(bloomDay, m, k);
}

int main()
{
    
    return 0;
}