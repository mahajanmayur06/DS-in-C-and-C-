#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int lps(string str1) {
    string str2 = str1;
    reverse(str2.begin(), str2.end());
    int len = str1.size();
    vector<int> dp(len + 1, 0);
    for (int i = 1; i <= len; i++) {
        int prev = 0;
        for (int j = 1; j <= len; j++) {
            int temp = dp[j];
            if (str1[i - 1] == str2[j - 1]) 
                dp[j] = 1 + prev;
            else 
                dp[j] = max(dp[j], dp[j-1]);
            prev = temp;
        }
    }
    return dp[len];
}

int minInsertions(string s) {
    int len = lps(s);
    int n = s.size();
    return n - len;
}

int main()
{
    string str = "leetcode";
    cout << minInsertions(str);
    return 0;
}