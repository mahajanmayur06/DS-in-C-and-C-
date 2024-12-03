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

void left_side(Node* root, vector<int>& left_nodes) {
    Node* curr = root->left;
    while (curr) {
        if (!curr->left || !curr->right) {
            left_nodes.push_back(curr->data);
        }
        if (curr->left) {
            curr = curr->left;
        }
        else {
            curr = curr->right;
        }
    }
}

void left_part(Node* root, vector<int>& left_nodes) {
    if (root->left == NULL && root->right == NULL) return;
    if (root->left) {
        left_nodes.push_back(root->data);
        left_part(root->left, left_nodes);
    }
    else {
        left_nodes.push_back(root->data);
        left_part(root->right, left_nodes);
    }
}

void right_part(Node* root, vector<int>& right_nodes) {
    if (root->left == NULL && root->right == NULL) return;
    if (root->right) {
        right_nodes.push_back(root->data);
        right_part(root->right, right_nodes);
    }
    else {
        right_nodes.push_back(root->data);
        right_part(root->left, right_nodes);
    }
}

void leaf_part(Node* root, vector<int>& leaf_nodes) {
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL) {
        leaf_nodes.push_back(root->data);
        return;
    }
    leaf_part(root->left, leaf_nodes);
    leaf_part(root->right, leaf_nodes);
}

void boundary_traversal (Node* root) {
    vector<int> ans, left, right, leaf;
    left_part(root, left);
    ans.insert(ans.end(), left.begin(), left.end());
    leaf_part(root, leaf);
    ans.insert(ans.end(), leaf.begin(), leaf.end());
    if (root->right) {
        right_part(root->right, right);
        ans.insert(ans.end(), right.rbegin(), right.rend());
    }
    cout << "Boundary Traversal: " << endl;
    for (int num : ans) {
        cout << num << " ";
    }

}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(10);
    root->right->right->left = new Node(11);
    root->right->right->right = new Node(12);

    boundary_traversal(root);
    return 0;
}
