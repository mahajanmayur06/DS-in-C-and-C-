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

int childSum (TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftVal = 0, rightVal = 0;
    if (root->left) leftVal = childSum(root->left);
    if (root->right) rightVal = childSum(root->right);
    int childSum = leftVal + rightVal;

    if (childSum >= root->val) {
        root->val = childSum;
    }
    else {
        if (root->left) 
            root->left->val = root->val;
        if (root->right)
            root->right->val = root->val;
    }
    
    return root->val;
}

void printTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}

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


int main()
{
    TreeNode* root = createTree();
    int top = childSum(root);
    printTree(root);
    return 0;
}