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

// map top node of tree to its level 
vector<int> top_view (Node* root) {
    queue<pair<Node*, int>> q;
    map<int, int> nodes; // {level, node}
    q.push({root, 0});
    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        Node* node = front.first;
        int x = front.second;
        if (nodes.find(x) == nodes.end()) {
            nodes[x] = node->data;
        }
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

}