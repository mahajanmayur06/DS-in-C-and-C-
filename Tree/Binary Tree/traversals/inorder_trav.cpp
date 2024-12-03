#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
    
vector<int> inorderTraversal(TreeNode* root,vector<int> v) {
    if (root == NULL)
        return v;
    v = inorderTraversal(root->left, v);
    v.push_back(root->val) ;
    v = inorderTraversal(root->right, v);
    return v;
}

// If we got null we should pop top element of the stack 
vector<int> inorder (TreeNode* root) {
    vector<int> inorder;
    stack<TreeNode*> st;
    TreeNode* curr = root;
    while (true) {
        if (!curr) {
            if (st.empty()) break;
            curr = st.top();
            st.pop();
            inorder.push_back(curr->val);
            curr = curr->right;
        }
        else {
            st.push(curr);
            curr = curr->left;
        }
    }
    return inorder;
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