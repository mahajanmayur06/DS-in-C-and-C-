#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// longest palindromic subsequence is lcs between a string and its reverse

int lcs(string str1, string str2) {
    int len1 = str1.size(), len2 = str2.size();
    if (len1 < len2) {
        swap(str1, str2);
        swap(len1, len2);
    }
    vector<int> dp(len2 + 1, 0);
    for (int i = 1; i <= len1; i++) {
        int prev = 0;
        for (int j = 1; j <= len2; j++) {
            int temp = dp[j];
            if (str1[i - 1] == str2[j - 1]) 
                dp[j] = 1 + prev;
            else 
                dp[j] = max(dp[j], dp[j-1]);
            prev = temp;
        }
    }
    return dp[len2];
}

int main()
{
    string str1 = "babdccd";
    string str2 = str1;
    reverse(str2.begin(), str2.end());
    cout << lcs(str1, str2);
    return 0;
}