#include <bits/stdc++.h>
using namespace std;

vector<int> findPSE (vector<int>& arr) {
    int n = arr.size();
    stack<int> st;
    vector<int> res(n, -1);
    
    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }
        if (!st.empty()) {
            res[i] = st.top();
        }
        st.push(arr[i]);
    }
    return res;
}

int main() {
    vector<int> arr = {4, 12, 5, 3, 1, 2, 5, 3, 1, 2, 4, 6};
    vector<int> res = findPSE(arr);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " "; 
    }
    return 0;
}