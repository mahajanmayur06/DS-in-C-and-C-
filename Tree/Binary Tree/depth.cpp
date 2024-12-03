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

int maxDepth(TreeNode* root) {
    if (!root)
        return 0;
    int maxLeft = maxDepth(root->left);
    int maxRight = maxDepth(root->right);
    return max(maxLeft, maxRight) + 1;
}

int main()
{
    
    return 0;
}