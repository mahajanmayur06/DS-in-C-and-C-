#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    int i = 0, j = nums.size() - 1;
    int leftProduct = 1, rightProduct = 1;
    vector<int> res(nums.size() , 1);
    
    while (i < nums.size() && j > -1)
    {
        res[i] *= leftProduct;
        leftProduct *= nums[i];
        res[j] = res[j] * rightProduct;
        rightProduct *= nums[j];
        i++;
        j--;
    }
    return res;
}

int main()
{
    vector<int> v = {1, 2, 3, 4};
    vector<int> ans = productExceptSelf(v);
    for (int i : ans) cout << i << " ";
    return 0;
}