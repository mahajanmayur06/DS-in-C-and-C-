#include <bits/stdc++.h>
using namespace std;

int countPalindromicSubsequence(string s) {
    int n = s.size();
    set<char> st;
    set<pair<char, char>> res;
    unordered_map<char, int> map;
    for (int i = 0; i < n; i++) {
        map[s[i]]++;
    }
    for (char mid : s) {
        map[mid]--;
        for (char ch : st) {
            if (map[ch] > 0) {
                res.insert({mid, ch});
            }
        }
        st.insert(mid);
    }
    return res.size();
}

int main()
{
    int res = countPalindromicSubsequence("abab");
    cout << res << endl;
    return 0;
}