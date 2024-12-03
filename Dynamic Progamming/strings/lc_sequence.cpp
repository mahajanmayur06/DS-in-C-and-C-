#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// recursion
int recursion(string str1, string str2, int ind1, int ind2) {
    if (ind1 < 0 || ind2 < 0) {
        return 0;
    }
    if (str1[ind1] == str2[ind2]) {
        return 1 + recursion(str1, str2, ind1 - 1, ind2 - 1);
    }
    return max(recursion(str1, str2, ind1 - 1, ind2), recursion(str1, str2, ind1, ind2 - 1));
}

// tabulation
int tabulation(string str1, string str2) {
    int len1 = str1.size(), len2 = str2.size();
    vector<vector<int>> dp(len1 + 1, vector<int> (len2 + 1, 0));

    for (int i = 1; i < len1 + 1; i++) {
        for (int j = 1; j < len2 + 1; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = 0 + max(dp[i-1][j], dp[i][j - 1]);
            }
        }
    }
    // for (auto num1 : dp) {
    //     for (int num : num1) {
    //         cout << num << " ";
    //     }
    //     cout << endl;
    // }
    return dp[len1][len2];
}
 
// space optimisation
int space_optimisation(string str1, string str2) {
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
        // for (int num : dp) {
        //     cout << num << " ";
        // }
        // cout << endl;
    }
    return dp[len2];
}

// print LCS
void printLCS (string str1, string str2) {
    int len1 = str1.size(), len2 = str2.size();
    vector<vector<int>> dp(len1 + 1, vector<int> (len2 + 1, 0));

    for (int i = 1; i < len1 + 1; i++) {
        for (int j = 1; j < len2 + 1; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = 0 + max(dp[i-1][j], dp[i][j - 1]);
            }
        }
    }

    string res(dp[len1][len2], ' ');
    int len = dp[len1][len2] - 1;
    int i = len1, j = len2;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            res[len--] = str1[i - 1];
            i--;
            j--;
        }
        else {
            if (dp[i - 1][j] < dp[i][j - 1]) {
                j--;
            }
            else {
                i--;
            }
        }
        
    }
    cout << res;
}

int main()
{
    string str1 = "abce";
    string str2 = "ecde";
    int len1 = str1.size(), len2 = str2.size();
    // cout << recursion(str1, str2, len1 - 1, len2 - 1) << endl;
    // cout << tabulation(str1, str2) << endl;
    // cout << space_optimisation(str1, str2) << endl;
    printLCS(str1, str2);
    return 0;
}