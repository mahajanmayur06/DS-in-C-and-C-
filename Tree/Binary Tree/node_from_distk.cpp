#include <bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left, *right;
    TreeNode(int data) {
        val = data;
        left = NULL;
        right = NULL;
    }
};
TreeNode* createTree() {
    TreeNode* root = new TreeNode(12);
    root->left = new TreeNode(30);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(36);
    root->left->right = new TreeNode(12);
    root->right->left = new TreeNode(18);
    root->right->right = new TreeNode(30);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(13);

    return root;
}

void markParents (TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parents ) {
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        if (curr->left) {
            parents[curr->left] = curr;
            q.push(curr->left);
        }
        if (curr->right) {
            parents[curr->right] = curr;
            q.push(curr->right);
        }   
    }
}

vector<int> distanceK (TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*> parents;
    unordered_map<TreeNode*, bool> visited;
    queue<TreeNode*> q;
    markParents(root, parents);
    q.push(target);
    visited[target] = true;
    for (int level = 0; level < k ; level++) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            auto curr = q.front();
            q.pop();
            if (curr->left && !visited[curr->left]) {
                q.push(curr->left);
                visited[curr->left] = true;
            }
            if (curr->right && !visited[curr->right]) {
                q.push(curr->right);
                visited[curr->right] = true;
            }
            if (parents[curr] && !visited[parents[curr]]) {
                q.push(parents[curr]);
                visited[parents[curr]] = true;
            }
        }
    }
    vector<int> res;
    while (!q.empty()) {
        res.push_back(q.front()->val);
        q.pop();
    }
    return res;
}

// TC : O(2N)
int main()
{
    TreeNode* root = createTree();
    TreeNode* target = root->left;
    int k = 1;
    vector<int> ans = distanceK(root, target, k);
    for (int i : ans) {
        cout << i << " ";
    }
    return 0;
}