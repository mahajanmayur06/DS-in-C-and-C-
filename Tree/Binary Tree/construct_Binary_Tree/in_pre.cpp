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

TreeNode* BinaryTree(vector<int>& pre, int l1, int r1, vector<int>& in, int l2, int r2, unordered_map<int, int>& map) {
    if (l1 > r1 || l2 > r2) return NULL;
    TreeNode* root = new TreeNode(pre[l1]);
    int mid = map[pre[l1]];
    int numsLeft = mid - l2;
    root->left = BinaryTree(pre, l1 + 1, l1 + numsLeft, in, l2, mid - 1, map);
    root->right = BinaryTree(pre, l1 + numsLeft + 1, r1, in, mid + 1, r2, map);
    return root;
}

TreeNode* createBinaryTree (vector<int>& in, vector<int>& pre) {
    int n = in.size();
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++) map[in[i]] = i;
    TreeNode* root = BinaryTree(pre, 0, n - 1, in, 0, n - 1, map);
    return root;
}

int main()
{
    vector<int> in = {40, 20, 50, 10, 60, 30};
    vector<int> pre = {10, 20, 40, 50, 30, 60};
    return 0;
}