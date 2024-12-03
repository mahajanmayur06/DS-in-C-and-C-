#include <bits/stdc++.h>
using namespace std;

// crazy question

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

int maxWidth (TreeNode* root) {
    if (!root) {
        return 0;
    }
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    int width = 0;
    while (!q.empty()) {
        int minDist = q.front().second;
        int size = q.size();
        int first, last;
        for (int i = 0; i < size; i++) {
            int currIndex = q.front().second - minDist;
            TreeNode* node = q.front().first;
            q.pop();
            if (i == 0) first = currIndex;
            if (i == size - 1) last = currIndex;
            if (node->left) {
                q.push({node->left, currIndex * 2 + 1});
            }
            if (node->right) {
                q.push({node->right, currIndex * 2 + 2});
            }
        }
        width = max(width, last - first + 1);
    }
    return width;        
}
int main()
{
    
    return 0;
}