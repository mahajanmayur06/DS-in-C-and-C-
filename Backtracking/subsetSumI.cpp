#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void subSetSum(vector<int> &arr, vector<int> &subSet, int ind, int sum){
    if (ind >= arr.size()){
        subSet.push_back(sum);
        return;
    }
    subSetSum(arr, subSet, ind + 1, sum + arr[ind]); // This case for picking the elements 
    subSetSum(arr, subSet, ind + 1, sum); // This case for not picking the elements
}

int main()
{
    vector<int> arr = {3, 1, 2};
    vector<int> subSet;
    subSetSum(arr,subSet, 0 , 0);
    sort(subSet.begin(), subSet.end());

    for (int i = 0; i < subSet.size(); i++){
        cout << subSet[i] << " ";
    }
    
    return 0;
}