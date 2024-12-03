#include <iostream>
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

void right_side_view (Node* root, int level, vector<int>& right_side) {
    if (!root) return;
    if (level == right_side.size()) {
        right_side.push_back(root->data);
    }
    if (root->right) {
        right_side_view(root->right, level + 1, right_side);
    }
    if (root->left) {
        right_side_view(root->left, level + 1, right_side);
    }
}
Node* createSampleTree() {
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(25);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    return root;
}

int main() {
    vector<int> ans;
    Node* root = createSampleTree();
    right_side_view(root, 0, ans);
    for (int num : ans) {
        cout << num << " ";
    }
    return 0;
}