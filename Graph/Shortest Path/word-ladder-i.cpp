#include <bits/stdc++.h>
using namespace std;

int word_ladder(vector<string>& wordList, string beginWord, string endWord) {
    int n = wordList.size();
    unordered_map<string, int> visited;
    int count = 0;
    queue<pair<string, int>> q;
    unordered_set<string> set(wordList.begin(), wordList.end()); // try to erase string when visited
    q.push({beginWord, 1});
    visited[beginWord] = 1;
    while (!q.empty()) {
        string word = q.front().first;
        int count = q.front().second;
        q.pop();
        for (int i = 0; i < word.size(); i++) {
            for (char k = 'a'; k <= 'z'; k++) {
                string str = word;
                str[i] = k;
                if (set.count(str) && !visited.count(str)) {
                    visited[str] = 1;
                    set.erase(str);
                    q.push({str, count + 1});
                    if (str == endWord) {
                        return count + 1;
                    }
                }
            }
        }
    }
    return 0;
}

// TC : O(N * word.length * 26 * 1)
int main()
{
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    string beginWord = "hit", endWord = "cog";
    int ans = word_ladder(wordList, beginWord, endWord);
    cout << ans;
    // cout << (char)('a' + 0) << " " << (char)('a' + 25);
    return 0;
}