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

// void get_paths (Node* root, vector<string>& paths, string path) {
//     if (root->left == NULL && root->right == NULL) {
//         path += to_string(root->data);
//         paths.push_back(path);
//         return;
//     }
//     if (root->left) {
//         path += to_string(root->data);
//         get_paths(root->left, paths, path);
//         path.pop_back();
//     }
//     if (root->right) {
//         path += to_string(root->data);
//         get_paths(root->right, paths, path);
//         path.pop_back();
//     }
// }

void get_paths (Node* root, vector<string>& paths, string path) {
    if (root->left == NULL && root->right == NULL) {
        paths.push_back(path + to_string(root->data));
        return;
    }
    if (root->left) {
        get_paths(root->left, paths, path + to_string(root->data) + "->");
    }
    if (root->right) {
        get_paths(root->right, paths, path + to_string(root->data) + "->");
    }
}
void get_path_to_node (Node* root, vector<string>& paths, string path, int value) {
    if (root->data == value) {
        paths.push_back(path + to_string(root->data));
        return;
    }
    if (root->left) {
        get_path_to_node(root->left, paths, path + to_string(root->data) + "->", value);
    }
    if (root->right) {
        get_path_to_node(root->right, paths, path + to_string(root->data) + "->", value);
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    // string path = "";
    vector<string> paths;
    get_paths(root, paths, "");
    for (auto string : paths) {
        cout << string << endl;
    }
    return 0;
}