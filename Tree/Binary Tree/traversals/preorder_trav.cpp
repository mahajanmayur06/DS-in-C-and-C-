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

// data left right
vector<int> preorderTraversal(Node* root) {
    vector<int> preorder;
    if (root == NULL) {
        return preorder;
    }
    stack<Node*> s;
    s.push(root);
    while (!s.empty()) {
        Node* node = s.top();
        preorder.push_back(node->data);
        s.pop();
        if (node->right) s.push(node->right);
        if (node->left) s.push(node->left);
    }
    return preorder;
}

vector<int> v;
vector<int> preorderTraversal(Node* root) {
    if (root == NULL)
        return v;
    v.push_back(root->data);
    v = preorderTraversal(root->left);
    v = preorderTraversal(root->right);
    return v;
}
int main()
{
    
    return 0;
}