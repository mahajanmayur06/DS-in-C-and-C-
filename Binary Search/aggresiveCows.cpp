#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int NoOfCows (vector<int>& nums, int dist) {
    int count = 1;
    int n = nums.size();
    int last = nums[0];
    for (int i = 1; i < n; i++) {
        int gap = nums[i] - last;
        if (gap >= dist) {
            count++;
            last = nums[i];
        }
    }
    return count;
}

int minimumGap (vector<int>& nums, int cows) {
    sort(nums.begin(), nums.end());
    int l = nums[0], r = nums[nums.size() - 1] - nums[0];
    while (l <= r) {
        int mid = l + (r - l) / 2;
        int cows_count = NoOfCows(nums, mid);
        if (cows_count >= cows) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return r; // we want maximum distance of minimum distances between cows
}
int main()
{
    vector<int> nums = {0, 3, 4, 7, 10, 9};
    int cows = 4;
    cout << minimumGap(nums, cows);
    return 0;
}