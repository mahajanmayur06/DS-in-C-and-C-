#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& nums) {
    int l = 0; 
    int r = nums.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (mid == 1) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return l;
}
vector<int> maxNoOfOnes (vector<vector<int>>& nums) {
    int n = nums.size();
    int m = nums[0].size();
    int index = 0, count = 0;

    for (int i = 0; i < n; i++){
        int countOne = binarySearch(nums[i]); // we can use lower bound of 1 OR upper bound of 0
        if (countOne > count) {
            count = countOne;
            index = i;
        }
    }
    return {index, m - count + 1};
}
int main()
{
       
    return 0;
}