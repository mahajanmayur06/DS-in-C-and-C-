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

vector<int> bottom_view (Node* root) {
    queue<pair<Node*, int>> q;
    map<int, int> nodes;
    q.push({root, 0});
    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        Node* node = front.first;
        int x = front.second;
        nodes[x] = node->data;
        if (node->left) {
            q.push({node->left, x - 1});
        }
        if (node->right) {
            q.push({node->right, x + 1});
        }
    }
    vector<int> ans;
    for (auto p : nodes) {
        ans.push_back(p.second);
    }
    return ans;
}

int main() {
    Node* root = createSampleTree();
    vector<int> ans = bottom_view(root);
    for (int n : ans) {
        cout << n << " ";
    }
    return 0;
}