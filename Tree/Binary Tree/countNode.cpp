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

TreeNode* createCompleteBinaryTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    return root;
}

// O(N)
int countNodes (TreeNode* root) {
    if (!root->left && !root->right) return 1;
    int leftCount = 0, rightCount = 0;
    if (root->left) leftCount = countNodes(root->left);
    if (root->right) rightCount = countNodes(root->right);
    return leftCount + rightCount + 1;
}

// O((logN) ^ 2)
int findLeftHeight (TreeNode* root) {
    int h = 0;
    while (root) {
        h++;
        root = root->left;
    }
    return h;
}
int findRightHeight (TreeNode* root) {
    int h = 0;
    while (root) {
        h++;
        root = root->right;
    }
    return h;
}

int findTotalNodes(TreeNode* root) {
    if (!root) return 0;
    int lh = findLeftHeight(root);
    int rh = findRightHeight(root);
    if (lh == rh) return (1 << lh) - 1;
    return 1 + findTotalNodes(root->left) + findTotalNodes(root->right);
}

// driver code
int main()
{
    TreeNode* root = createCompleteBinaryTree();
    int count = countNodes(root);
    cout << count << " " << findTotalNodes(root);
    return 0;
}