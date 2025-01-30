#include <bits/stdc++.h>
using namespace std;

string shortest_superseq (string s1, string s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp (n + 1, vector<int> (m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    string res = "";
    int i = n, j = m;
    while (i >= 1 && j >= 1) {
        if (s1[i - 1] == s2[j - 1]) {
            res = s1[i - 1] + res;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            res = s1[i - 1] + res;
            i--;
        }
        else {
            res = s2[j - 1] + res;
            j--;
        }
    }
    while (i > 0) {
        res = s1[i - 1] + res;
        i--;
    }
    while (j > 0) {
        res = s2[j - 1] + res;
        j--;
    }
    cout << dp[n][m] << endl;
    return res;
}

int main() {
    string s1 = "brute", s2 = "groot";
    cout << shortest_superseq(s1, s2) << endl;
    return 0;
}