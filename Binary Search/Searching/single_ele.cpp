#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    if (right == 0) {
        return nums[0];
    }
    if (nums[left] != nums[left + 1]) return nums[left];
    if (nums[right] != nums[right - 1]) return nums[right];
    left++;
    right--;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]) {
            return nums[mid];
        }
        if (mid%2 == 1) {
            if (nums[mid] == nums[mid + 1]) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        else {
            if (nums[mid] == nums[mid + 1]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
    
    return 0;
}