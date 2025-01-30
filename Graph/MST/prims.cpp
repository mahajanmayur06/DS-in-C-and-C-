#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> primsAlgo (vector<vector<pair<int, int>>>& adjList) {
    int n = adjList.size();
    vector<bool> visited (n, false);
    vector<pair<int, int>> mst;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;  // {wt, node, parent}
    pq.push({0, 0, -1});
    int sum = 0;

    while (!pq.empty()) {
        auto top = pq.top();
        int wt = get<0>(top), node = get<1>(top), par = get<2>(top);
        pq.pop();
        if (visited[node]) 
            continue;
        visited[node] = true;
        sum += wt;
        if (par != -1) mst.push_back({par, node});
        for (auto adj : adjList[node]) {
            int adjNode = adj.first, weight = adj.second;
            if (!visited[adjNode]) {
                pq.push({weight, adjNode, node});
            }
        }
    }
    cout << sum << endl;
    return mst;
}
int main()
{
    vector<vector<pair<int, int>>> adjList = {
        {{1, 2}, {2, 3}},
        {{0, 2}, {2, 4}, {3, 5}},
        {{0, 3}, {1, 4}, {3, 1}},
        {{1, 5}, {2, 1}}
    };
    vector<pair<int, int>> mst = primsAlgo(adjList); 
    for (auto edge : mst) {
        cout << edge.first << " " << edge.second << endl; 
    }

    return 0;
}