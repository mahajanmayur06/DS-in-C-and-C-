#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int V; 

int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
 
    return min_index;
}

void printMST(int parent[], vector<vector<int>>& graph,int startIndex) {
    cout << "Edge \tWeight\n";
    int totalWeight = 0;
    int i = (startIndex+1)%V;
    do{
        cout << parent[i] << " - " << i << " \t" << graph[parent[i]][i] << " \n";
        totalWeight += graph[parent[i]][i];
        i = (++i) % V;
    }while(i != startIndex);
    cout << "Total weight of MST: " << totalWeight << endl;
}

void primMST(vector<vector<int>>& graph,int startIndex) {
    int parent[V];
    int key[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
 
    key[startIndex] = 0;
    parent[startIndex] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
 
        mstSet[u] = true;
        cout << "We are on node : "<< u <<endl;
 
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
            {
                parent[v] = u, key[v] = graph[u][v];
                cout << "Neighbour found is node : " << v << endl;
            }
               
       
    }
 
    printMST(parent, graph, startIndex);
}

int main() {
    int startIndex = 0;
   
    cout << "Enter no. of vertices : ";
    cin >> V;
    cout << "Enter start index : ";
    cin >> startIndex;
   
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
 
    primMST(graph,startIndex);
 
    return 0;
}
