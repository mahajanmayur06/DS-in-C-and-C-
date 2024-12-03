#include <iostream>
#include <vector>
using namespace std;

// Function to find all subsets that sum up to target
void subsetSum(vector<int>& nums, int target, int index, vector<int>& subset, vector<vector<int>>& result) {
    // If target is achieved, add current subset to result
    if (target == 0) {
        result.push_back(subset);
        return;
    }

    // If target is negative or no elements left in array
    if (target < 0 || index == nums.size()) {
        return;
    }


    subset.push_back(nums[index]);
    subsetSum(nums, target - nums[index], index + 1, subset, result);

    // Exclude current element from the subset
    subset.pop_back();
    subsetSum(nums, target, index + 1, subset, result);
}

// Function to print all subsets that sum up to target
void printSubsetSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    vector<int> subset;
    subsetSum(nums, target, 0, subset, result);

    // Printing the subsets
    for (const auto& vec : result) {
        cout << "[";
        for (int i = 0; i < vec.size(); ++i) {
            cout << vec[i];
            if (i < vec.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int target = 7;
    cout << "Subsets that sum up to " << target << ":" << endl;
    printSubsetSum(nums, target);
    return 0;
}