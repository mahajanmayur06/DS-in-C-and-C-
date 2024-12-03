#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left, *right;
    TreeNode(int data) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int height (TreeNode* root, int& dia) {
    if (root == NULL) 
        return 0;
    int lh = height(root->left, dia);
    int rh = height(root->right, dia);
    dia = max(dia, lh + rh);
    return 1 + max(lh, rh);
}

int diameterOfBinaryTree(TreeNode* root) {
    int dia = 0;
    int d = height(root, dia);
    return dia;
}

int main()
{
    
    return 0;
}