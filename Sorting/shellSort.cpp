#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Solution with O(m+n) space
void merge(vector<int> &arr1, vector<int>& arr2) {
    int m = arr1.size();
    int n = arr2.size();
    vector<int> sorted(n+m);

    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            sorted[k++] = arr1[i];
            i++;
        }
        else {
            sorted[k++] = arr2[j];
            j++;
        }
    }
    while (i < n) {
        sorted[k++] = arr1[i];
        i++;
    }
    while (j < m) {
        sorted[k++] = arr2[j];
        j++;
    }
    for (int num : sorted) {
        cout << num << " ";
    }
    cout << endl;
}

// Solution with O(1) space solution
void shellSort(vector<int> &arr1, vector<int>& arr2) {
    int m = arr1.size();
    int n = arr2.size();
    float gap = (m + n)/2 + (m+n)%2;

    bool cmp = false;
    while (gap >= 1 ) {
        cout << gap << endl;
        int left = 0;
        int right = gap ;
        while (right < m + n) {
            int i, j;
            if (left < m && right < m) {
                if (arr1[left] > arr1[right]) swap(arr1[left], arr1[right]);
            }
            else if (left < m && right >= m ) {
                if (arr1[left] > arr2[right - m]) swap(arr1[left], arr2[right - m]);
            }
            else {
                if (arr2[left - m] > arr2[right - m]) swap(arr2[left - m], arr2[right - m]);
            }
            left++;
            right++;
        }
        if (gap == 1) break;
        gap = ceil(gap/2);
    }
    // for (int num : arr1) {
    //     cout << num << " ";
    // }
    // for (int num : arr2) {
    //     cout << num << " ";
    // }
}
int main()
{
    // Two sorted array we have to merget them within O(1) space
    vector<int> arr1 = {2, 3};
    vector<int> arr2 = {1};
    // vector<int> arr1 = {1,5,8,10,12,19};
    // vector<int> arr2 = {3,4,9,11,15,18};
    merge(arr1, arr2);
    shellSort(arr1, arr2);
    return 0;
}