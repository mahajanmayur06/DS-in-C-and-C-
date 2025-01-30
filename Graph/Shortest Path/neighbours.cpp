#include <bits/stdc++.h>
using namespace std;

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> dist (n, vector<int> (n, INT_MAX));
    for (int i = 0; i < n; i++) dist[i][i] = 0;

    for (auto& e : edges) {
        dist[e[0]][e[1]] = dist[e[1]][e[0]] = e[2];
    }
    
    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    int d = dist[i][k] + dist[k][j];
                    if (d <= distanceThreshold)
                        dist[i][j] = min(dist[i][j], d);
                }
            }
        }
    }
    int minCity = n, cities = n;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (dist[i][j] <= distanceThreshold) {
                count++;
            }
        }
        if (count <= cities) {
            cities = count;
            minCity = i;
        }
    }
    return minCity;
}
int main()
{
    int n1 = 4;
    vector<vector<int>> edges1 = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
    int distanceThreshold1 = 4;
    int n2 = 5;
    vector<vector<int>> edges2 = {{0,1,2},{0,4,8},{1,2,3},{1,4,2},{2,3,1},{3,4,1}};
    int distanceThreshold2 = 2;
    cout << findTheCity(n1, edges1, distanceThreshold1) << endl;
    cout << findTheCity(n2, edges2, distanceThreshold2) << endl;
    return 0;
}