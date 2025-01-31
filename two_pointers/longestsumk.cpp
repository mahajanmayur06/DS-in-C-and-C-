#include <bits/stdc++.h>
using namespace std;

int findLength (vector<int>& nums, int k) {
    int left = 0;
    int sum = 0, maxLen = 0;
    for (int right = 0; right < nums.size(); right++) {
        sum += nums[right];
        while (sum > k) {
            sum -= nums[left];
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}
int findLength2 (vector<int>& nums, int k) {
    int left = 0;
    int sum = 0, maxLen = 0;
    for (int right = 0; right < nums.size(); right++) {
        sum += nums[right];
        if (sum > k) {
            sum -= nums[left];
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}
int main() {
    
    return 0;
}