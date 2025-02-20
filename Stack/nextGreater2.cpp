#include <bits/stdc++.h>
using namespace std;

vector<int> findNGE2 (vector<int>& arr) {
    int n = arr.size();
    stack<int> st;
    vector<int> res(n, -1);
    for (int i = 2 * n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= arr[i % n]) {
            st.pop();
        }
        if (!st.empty()) {
            res[i % n] = st.top();
        }
        st.push(arr[i % n]);
    }
    return res;
}

int main() {
    vector<int> arr = {4, 12, 5, 3, 1, 2, 5, 3, 1, 2, 4, 6};
    vector<int> res = findNGE2(arr);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " "; 
    }
    return 0;
}