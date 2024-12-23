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

TreeNode* createBinaryTree (vector<int>& post, int l1, int r1, int l2, int r2, unordered_map<int, int>& map) {
    if (l2 > r2 || l1 > r1) 
        return NULL;
    TreeNode* root = new TreeNode(post[r1]);
    int mid = map[post[r1]];
    int numsLeft = mid - l2;
    root->left = createBinaryTree(post, l1, l1 + numsLeft - 1, l2, mid - 1, map);
    root->right = createBinaryTree(post, l1 + numsLeft, r1 - 1, mid + 1, r2, map);
    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n = inorder.size();
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++) {
        map[inorder[i]] = i;
    }
    return createBinaryTree (postorder, 0, n - 1, 0, n - 1, map);
}

int main()
{
    
    return 0;
}