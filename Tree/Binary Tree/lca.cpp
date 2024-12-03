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

Node* lca (Node* root, int n1, int n2) {
    if (root == NULL) return NULL;
    if (root->data == n1 || root->data == n2) {
        return root;
    }
    Node* left = lca(root->left, n1, n2);
    Node* right = lca(root->right, n1, n2);
    if (left && right) {
        return root; // if at any node we found left and right exists i.e, its not null, root is the lca
    }
    return left ? left : right;
}

int main()
{
    
    return 0;
}