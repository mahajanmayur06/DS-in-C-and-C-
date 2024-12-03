#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> word_ladder(string beginWord, string endWord, vector<string>& wordList) {
    int n = wordList.size();
    unordered_set<string> set(wordList.begin(), wordList.end());
    vector<vector<string>> ans;
    queue<vector<string>> q;
    q.push({beginWord});
    int level = 1;
    while (!q.empty()) {
        
    }
    return ans;
}

int main()
{
    
    return 0;
}