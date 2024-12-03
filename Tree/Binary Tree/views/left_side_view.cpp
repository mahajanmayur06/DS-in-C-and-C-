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

vector<int> left_side_view (Node* root) {
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    vector<int> left;
    while (!q.empty()) {
        auto node = q.front().first;
        int level = q.front().second;
        q.pop();
        if (left.size() == level) {
            left.push_back(node->data);
        }
        if (node->left) {
            q.push({node->left, level + 1});
        }
        if (node->right) {
            q.push({node->right, level + 1});
        }
    }
    return left;
}

int main() {
    vector<int> ans;
    Node* root = createSampleTree();
    vector<int> left = left_side_view(root);
    for (int num : left) {
        cout << num << " ";
    }
    return 0;
}