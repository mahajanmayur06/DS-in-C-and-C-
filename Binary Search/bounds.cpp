#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

// index = Lower Bound of x : smallest index for arr[index] >= x
int lowerBound(vector<int> nums, int x) {
    int low = 0;
    int high = nums.size() - 1;
    // int ans = nums.size();
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] >= x) {
        //     ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    // return ans;
    return low;
}

int upperBound(vector<int> nums, int x) {
    int low = 0;
    int high = nums.size() - 1;
    // int ans = nums.size();
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] > x) {
            // ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    // return ans;
    return low;
}

int floor (vector<int> nums, int x) {
    int low = 0;
    int high = nums.size() - 1;
    int ans = -1;
    while (high >= low)    {
        int mid = (low + high)/2;
        if (nums[mid] <= x) {
            ans = nums[mid];
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return ans;
}

int ceil (vector<int> nums, int x) {
    int low = 0;
    int high = nums.size() - 1;
    int ans = -1;
    while (high >= low)    {
        int mid = (low + high)/2;
        if (nums[mid] >= x) {
            ans = nums[mid];
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {   
    // vector<int> nums = {10, 10 ,10 , 20, 30, 30, 40, 50, 50 ,60, 70};
    // vector<int> nums = {5,5,5};
    vector<int> nums = {2,3,5,7};

    int x = 4;
    
    cout << "Custom lowerBound: " << lowerBound(nums, x) << endl;
    int lb = lower_bound(nums.begin(), nums.end(), x) - nums.begin();
    cout << "Standard lower_bound: " << lb << endl;

    cout << "Custom upperBound: " << upperBound(nums, x) << endl;
    int ub = upper_bound(nums.begin(), nums.end(), x) - nums.begin();
    cout << "Standard upper_bound: " << ub << endl;

    // floor and ceil
    // cout << floor(nums, 50);
    // cout << ceil(nums, 50);
    return 0;
}
