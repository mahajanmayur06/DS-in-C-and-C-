#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> ans;
    if (root == NULL) return ans;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++) {
            Node *node = q.front();
            q.pop();
            if (node->left) q.push(node->left); 
            if (node->right) q.push(node->right); 
            level.push_back(node->data);
        }
        ans.push_back(level);
    }
    return ans;
}

int main()
{
    
    return 0;
}