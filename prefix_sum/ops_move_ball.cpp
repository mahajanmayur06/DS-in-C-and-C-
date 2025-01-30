#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans (n, 0);
        int b = 0, m = 0;
        for (int i = 0; i < n; i++) {
            ans[i] = b + m;
            m = m + b;
            b += boxes[i] - '0';
        }

        b = 0, m = 0;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] += b + m;
            m = m + b;
            b += boxes[i] - '0';
        }
        return ans;
    }
};


int main()
{
    Solution obj;
    vector<int> res = obj.minOperations("11010");
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }    
    return 0;
}