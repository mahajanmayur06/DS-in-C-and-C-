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

string serialise (TreeNode* root) {
    TreeNode* curr = root;
    string res = "";
    queue<TreeNode*> q;
    q.push(curr);
    while (!q.empty()) {
        curr = q.front();
        q.pop();
        if (!curr) res += "#";
        else {
            res += to_string(curr->val);
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    return res;
}

TreeNode* deserialise (string str) {
    TreeNode* root;
    if (str[0] == '#') return NULL;
    root = new TreeNode(str[0] - '0');
    queue<TreeNode*> q;
    q.push(root);  
    int i = 1;
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        if (str[i] == '#') {
            curr->left = NULL;
            i++;
        }
        else {
            curr->left = new TreeNode(str[i] - '0');
            q.push(curr->left);
            i++;
        }
        if (str[i] == '#') {
            curr->right = NULL;
            i++;
        }
        else {
            curr->right = new TreeNode(str[i] - '0');
            q.push(curr->right);
            i++;
        }
    }
    return root;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    string res = serialise(root);
    cout << res << endl;
    TreeNode* newRoot = deserialise(res);
    cout << serialise(newRoot) << endl;
    return 0;
}