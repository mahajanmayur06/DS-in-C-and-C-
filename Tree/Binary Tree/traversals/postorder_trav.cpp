
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// using two stacks
vector<int> postorderTraversal(Node* root) {
    vector<int> postorder;
    if (root == NULL) {
        return postorder;
    }
    stack<Node*> s1;
    stack<Node*> s2;
    Node* node = root;
    s1.push(root);
    while (!s1.empty()) {
        Node* node = s1.top();
        s1.pop();
        s2.push(node);
        if (node->left) {
            s1.push(node->left);
        }
        if (node->right) {
            s1.push(node->right);
        }
    }
    while (!s2.empty()) {
        postorder.push_back(s2.top()->data);
        s2.pop();
    }
    return postorder;
}

// using 1 stack only
vector<int> postorder (Node* root) {
    vector<int> post;
    stack<Node*> st;
    Node* curr = root;
    while (!curr || !st.empty()) { // stack empty condition is needed to append root
        if (!curr) {
            st.push(curr);
            curr = curr->left;
        }
        else {
            Node* temp = st.top()->right;
            if (temp) {
                curr = temp;
            }
            else {
                temp = st.top();
                st.pop();
                post.push_back(temp->data);
                while (!st.empty() && st.top()->right == temp){
                    temp = st.top();
                    st.pop();
                    post.push_back(temp->data);
                }
            }
        }
    }
}
vector<int> v;
vector<int> postorderTraversal(Node* root) {
    if (root == NULL)
        return v;
    v = postorderTraversal(root->left);
    v = postorderTraversal(root->right);
    v.push_back(root->data);
    return v;
}
int main()
{
    
    return 0;
}
