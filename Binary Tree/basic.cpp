#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() {
        val = 0;
        left = NULL;
        right = NULL;
    }
    TreeNode(int data) {
        val = data;
        left = NULL;
        right = NULL;
    }
};

vector<int> preorderTraversal (TreeNode* root) {
    vector<int> pre;
    if (!root) return pre;
    stack<TreeNode*> s;
    s.push(root);
    while (!s.empty()) {
        TreeNode* node = s.top();
        s.pop();
        pre.push_back(node->val);
        if (root->left) s.push(root->left);
        if (root->right) s.push(root->right);
    }
    return pre;
}

int main()
{
    
    return 0;
}