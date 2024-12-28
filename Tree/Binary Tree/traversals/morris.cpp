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

vector<int> inorder (TreeNode* root) {
    vector<int> in;
    TreeNode* curr = root;

    while (curr != NULL) {
        if (curr->left == NULL) {
            in.push_back(curr->val);
            curr = curr->right;
        }
        else {
            TreeNode *prev = curr->left;
            while (prev->right && prev->right != curr) {
                prev = prev->right;
            }
            
            if (prev->right == NULL) {
                prev->right = curr;
                curr = curr->left;
            }
            else {
                prev->right = NULL;
                in.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    return in;
}

TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    return root;
}

int main()
{
    TreeNode* root = createSampleTree();
    vector<int> in = inorder(root);
    for (int num : in ) {
        cout << num << " ";
    }
    return 0;
}