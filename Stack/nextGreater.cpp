#include <bits/stdc++.h>
using namespace std;

vector<int> findNGE (vector<int>& arr) {
    int n = arr.size();
    stack<int> st;
    vector<int> res(n, -1);
    
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }
        if (!st.empty()) {
            res[i] = st.top();
        }
        st.push(arr[i]);
    }
    return res;
}

// TC : O(2N)
int main() {
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> res = findNGE(arr);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}