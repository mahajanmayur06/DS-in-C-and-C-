#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adjList, vector<bool>& visited, stack<int>& st, int node) {
    visited[node] = true;
    for (auto adjNode : adjList[node]) {
        if (!visited[adjNode]) {
            dfs (adjList, visited, st, adjNode);
        }
    }
    st.push(node);
}

vector<int> topologicalSort (vector<vector<int>>& adjList) {
    int n = adjList.size();
    stack<int> st;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs (adjList, visited, st, i);
        }
    }
    
    vector<int> arr;
    while (!st.empty()) {
        arr.push_back(st.top());
        st.pop();
    }
    return arr;
}

string alienDict (vector<string> dict, int k) {
    vector<vector<int>> graph(k);
    int size = dict.size();
    vector<bool> visited (k, false);
    for (int i = 0; i < size - 1; i++) {
        for (int m = 0, n = 0; m < dict[i].size() && n < dict[i + 1].size(); n++, m++) {
            if (dict[i][n] != dict[i + 1][m]) {
                if (!visited[dict[i + 1][m] - 'a']) {
                    graph[dict[i][n] - 'a'].push_back(dict[i + 1][m] - 'a');
                    visited[dict[i + 1][m] - 'a'] = true;
                    visited[dict[i][n] - 'a'] = true;
                }       
            }
        }
    }   
    vector<int> arr = topologicalSort(graph);
    string res = "";
    for (int i : arr) {
        res += ('a' + i);
    }
    return res;
}
int main()
{
    vector<string>dict = {"baa","abcd","abca","cab","cad"};
    int k = 4;
    cout << alienDict(dict, k);
    return 0;
}