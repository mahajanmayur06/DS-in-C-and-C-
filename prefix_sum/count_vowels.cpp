#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
    int n = words.size(), len = queries.size();
    vector<int> pre (n + 1, 0);
    for (int i = 0; i < n; i++) {
        if (isVowel(words[i][0]) && isVowel(words[i].back())) {
            pre[i + 1] = 1;
        }
        pre[i + 1] += pre[i];
    }
    vector<int> ans (len, 0);
    for (int i = 0; i < len; i++) {
        ans[i] = pre[queries[i][1] + 1] - pre[queries[i][0]];
    }
    return ans;
}

int main()
{
    vector<string> words = {"aba","bcb","ece","aa","e"};
    vector<vector<int>> queries = {{0,3},{2,3},{3,4},{0,4}};
    vector<int> res = vowelStrings(words, queries);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}