#include <bits/stdc++.h>
using namespace std;

int findLength (string s, int k) {
    int n = s.size();
    int left = 0;
    unordered_map<char, int> map;
    int maxLen = 0;
    for (int right = 0; right < n; right++) {
        map[s[right]]++;
        while (map.size() > k) {
            map[s[left]]--;
            if (map[s[left]] == 0){
                map.erase(s[left]);
            }
            left++;
        }
        if (map.size() <= k)
            maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}
int main() {
    string s = "aaabbccd";
    int k = 2;
    cout << findLength(s, k) << endl; 
    return 0;
}