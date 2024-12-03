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

// x : X-axis, level : Y-axis
vector<vector<int>> vertical_order_traversal(Node* root, vector<vector<int>>& trav) {
    map<int, map<int, multiset<int>>> nodes; // <x, <level, {nodes.val} >>
    queue<pair<Node*, pair<int, int>>> q; // <node, <x, level>> 
    q.push({root, {0, 0}});
    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        Node* node = front.first;
        int x = front.second.first;
        int y = front.second.second;
        nodes[x][y].insert(node->data);
        if (node->left) {
            q.push({node->left, {x - 1, y + 1}});
        }
        if (node->right) {
            q.push({node->right, {x + 1, y + 1}});
        }
    }
    vector<vector<int>> ans;
    for (auto p : nodes) {
        vector<int> col;
        for (auto q : p.second) {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}

int main() {

}