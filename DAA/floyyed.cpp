#include <iostream>
#include <vector>
#include <climits>
#include <string>

using namespace std;
const int INF = INT_MAX;

vector<vector<int>> floydWarshall(const vector<vector<int>> &graph)
{
    int V = graph.size();
    vector<vector<int>> dist(V, vector<int>(V));

    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
            dist[i][j] = graph[i][j];
    }

    for (int k = 0; k < V; ++k)
    {
        for (int i = 0; i < V; ++i)
        {
            for (int j = 0; j < V; ++j)
            {
                int minDist = dist[i][k] + dist[k][j];
                if (dist[i][k] != INF && dist[k][j] != INF && minDist < dist[i][j])
                    dist[i][j] = minDist;
            }
        }
    }
    return dist;
}

int main()
{
    vector<string> nodes = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"}; 
    vector<vector<int>> graph = {
        {0, 3, INF, 4, 1},
        {INF, 0, 5, INF, 5},
        {INF, INF, 0, 4, INF},
        {INF, 3, 1, 0, INF},
        {INF, INF, INF, INF, 0}
    };
    // vector<vector<int>> graph = {
    //     {0, 5, INF, 10},
    //     {INF, 0, 3, INF},
    //     {INF, INF, 0, 1},
    //     {INF, INF, INF, 0}
    // };

    vector<vector<int>> shortestDistances = floydWarshall(graph);

    cout << "   ";
    for (int i = 0; i < graph.size(); i++)
        cout << nodes[i] << "   ";
    cout << endl;

    for (int i = 0; i < shortestDistances.size(); ++i)
    {
        cout << nodes[i] << "  ";
        for (int j = 0; j < shortestDistances[i].size(); ++j)
        {
            if (shortestDistances[i][j] == INF)
                cout << "INF ";
            else
                cout << shortestDistances[i][j] << "   ";
        }
        cout << endl;
    }

    return 0;
}
