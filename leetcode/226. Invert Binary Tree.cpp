#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
};

    TreeNode* invertTree(TreeNode* root) {
        if (root != nullptr) {
            invertTree(root->left);
            invertTree(root->right);

            auto past_left = root->left;
            root->left = root->right;
            root->right = past_left;
        }
        return root;
    }

