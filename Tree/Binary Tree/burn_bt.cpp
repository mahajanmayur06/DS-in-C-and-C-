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

TreeNode* createRandomTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(5);
    root->right->right->left = new TreeNode(6);
    root->right->right->right = new TreeNode(7);
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

int time_to_burn (TreeNode* root, TreeNode* target) {
    unordered_map<TreeNode*, TreeNode*> parents;
    unordered_map<TreeNode*, bool> visited;
    queue<TreeNode*> q;
    markParents(root, parents);
    q.push(target);
    visited[target] = true;
    int time = 0;
    while (!q.empty()) {
        int size = q.size();
        time++;
        for (int i = 0; i < size; i++) {
            auto curr = q.front();
            q.pop();
            if (curr->left && visited[curr->left] ) {
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
    return time;
}

int main()
{
    TreeNode* root3 = createRandomTree();
    TreeNode* target3 = root3->right;
    int time3 = time_to_burn(root3, target3);
    cout << time3 ;
    return 0;
}