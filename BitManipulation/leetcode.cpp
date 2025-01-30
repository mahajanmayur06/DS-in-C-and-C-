#include <bits/stdc++.h>
using namespace std;

// Find single number in odd length array
int singleNumber (vector<int>& nums) {
    int res = 0;
    for (int num : nums) {
        res ^= num;
    }
    return res;
}

// Reverse the bits of a number
uint32_t reverseBits(uint32_t n) {
    uint32_t ans = 0;
    for (int i = 0; i < 32; i++) {
        if (n & (1 << i)) {
            ans |= (1 << (31 - i));
        }
    }
    return ans;
}

// Count the number of set bits in a number
int hammingWeight(int n) {
    int count = 0;
    while (n > 0) {
        count += n & 1;
        n = n >> 1;
    }
    return count;
}

// FInd missing number in array of [0...n]
int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int res = n;
    for (int i = 0; i < n; i++) {
        res ^= (i ^ nums[i]);
    }
    return res;
}


int main() {
    
    return 0;
}