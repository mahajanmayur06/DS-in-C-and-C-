#include <bits/stdc++.h>
using namespace std;

int count (string s) {
    int lastSeen[3] = {-1};
    int n = s.size(), ans = 0;

    for (int i = 0; i < n; i++) {
        lastSeen[s[i] - 'a'] = i;
        if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
            int minIndex = min({lastSeen[0], lastSeen[1], lastSeen[2]});
            ans += 1 + minIndex;
        }
    }
    return ans;
}
int main() {
    
    return 0;
}