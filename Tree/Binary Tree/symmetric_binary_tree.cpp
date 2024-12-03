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

bool func(Node* root1, Node* root2) {
    if (root1 == NULL && root2 == NULL) return true;
    if (!root1->left && root2->right || root1->left && !root2->right) return false;
    if (root1->data != root2->data) return false;
    return func(root1->left, root2->right) && func(root1->right, root2->left);
}

// iteratively
// bool isSymmetric (Node* root) {
//     Node *root1 = root, *root2 = root;
//     while (root1 && root2) {

//     }
//     return true;
// }

int main() {

}