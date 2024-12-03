#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int data) : val(data), left(nullptr), right(nullptr) {}
};

void print(vector<int>& pre, vector<int>& in, vector<int>& post) {
    cout << "Preorder Traversal : ";
    for (int num : pre) {
        cout << num << " ";
    }
    cout << endl;
    
    cout << "Inorder Traversal : ";
    for (int num : in) {
        cout << num << " ";
    }
    cout << endl;
    
    cout << "Postorder Traversal : ";
    for (int num : post) {
        cout << num << " ";
    }
    cout << endl;
}

void traversals(TreeNode* root) {
    stack<pair<TreeNode*, int>> st;
    vector<int> pre, in, post;
    st.push({root, 1});
    
    while (!st.empty()) {
        // auto &top = st.top(); 
        pair<TreeNode*, int> top = st.top(); 
        TreeNode* node = top.first;
        int num = top.second;
        
        if (num == 1) { // Preorder
            // top.second++;
            pre.push_back(node->val);
            st.pop();
            st.push({top.first, ++top.second});
            if (node->left) {
                st.push({node->left, 1});
            }
        } else if (num == 2) { // Inorder
            // top.second++;
            in.push_back(node->val);
            st.pop();
            st.push({top.first, ++top.second});
            if (node->right) {
                st.push({node->right, 1});
            }
        } else { // Postorder
            post.push_back(node->val);
            st.pop();
        }
    }
    print(pre, in, post);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(7);
    traversals(root);
    return 0;
}
