#include <iostream>
#include <bits/stdc++.h>
using namespace std;

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

int min_ops(string s1, string s2) {
    int len1 = s1.size(), len2 = s2.size();
    if (len1 < len2) { // No need to do it but just for understanding concept of question, we want len1 to be max
        swap(len2, len1);
    }
    int common = lcs(s1, s2);
    int del = len1 - common;
    int add = len2 - common;
    return del + add;
}

int main()
{
    string s1, s2;
    return 0;
}