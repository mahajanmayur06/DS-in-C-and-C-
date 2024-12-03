#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int students (vector<int> &nums, int pages) {
    int st = 1, pagesSt = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (pagesSt + nums[i] <= pages) {
            pagesSt += nums[i];
        }
        else {
            st++;
            pagesSt = nums[i];
        }
    }
}

// brute force approach --> go linear search from left(max) to right(sum)
// optimal solution using binary search algorithm
int allocateMaxBookPages (vector<int> &nums, int st) {
    int l = *max_element(nums.begin(), nums.end());
    // int sum = accumulate(nums.begin(), nums.end(), 0);
    int r = 0;
    for (int num : nums) r += num;
    while (l <= r) {
        int mid = (l + r) / 2;
        int reqStudents = students(nums, mid);
        if (reqStudents == st) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return l; // maximum number of pages that minimun no of student have
}
int main()
{
    
    return 0;
}