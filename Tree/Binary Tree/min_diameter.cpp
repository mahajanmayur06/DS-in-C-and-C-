#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left, *right;
    TreeNode(int data) {
        val = data;
        left = NULL;
        right = NULL;
    }
};

vector<vector<int>> buildTree(vector<vector<int>>& edge, int n){
    vector<vector<int>> tree(n);
    for (int i = 0; i < edge.size(); i++) {
        tree[edge[i][0]].push_back(edge[i][1]);
        tree[edge[i][1]].push_back(edge[i][0]);
    }
    return tree;
}

pair<int, int> maxDepth(vector<vector<int>>& tree, int cur, int par) {

}

int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
    int n = edges1.size() + 1;
    int m = edges2.size() + 1;
    vector<vector<int>> tree1 = buildTree(edges1, n);
    vector<vector<int>> tree2 = buildTree(edges2, m);
    auto d1 = maxDepth(tree1, 0, - 1);
    auto d2 = maxDepth(tree2, 0 ,-1);
    
}
int main()
{
    
    return 0;
}