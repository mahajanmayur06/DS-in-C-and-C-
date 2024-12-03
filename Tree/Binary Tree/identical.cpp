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

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == NULL && q == NULL ) {
        return true;
    }
    if (p == NULL || q == NULL || p->val != q->val) {
        return false;
    }
    bool t1, t2;
    t1 = isSameTree(p->left, q->left);
    t2 = isSameTree(p->right, q->right);
    return t1 && t2;
}

int main()
{
    
    return 0;
}