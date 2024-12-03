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

int getHeight(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    int leftH = getHeight(root->left);
    int rightH = getHeight(root->right);
    if (leftH == -1 || rightH == -1)
        return -1;
    if (abs(leftH - rightH) > 1)
        return -1;
    return max(leftH, rightH) + 1;
}

bool isBalanced(TreeNode* root) {
    if (getHeight(root) == -1) {
        return false;
    }
    return true;
}

int main()
{
    
    return 0;
}