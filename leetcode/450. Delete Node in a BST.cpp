#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* deleteNode(TreeNode* root, int key) {
    if (root != nullptr) {
        if (key == root->val) {
            if (root->left == nullptr) {
                return root->right;
            }
            if (root->right == nullptr) {
                return root->left;
            }
            TreeNode* furthest_right = root->left;
            while (furthest_right->right != nullptr) {
                furthest_right = furthest_right->right;
            }
            furthest_right->right = root->right;

            return root->left;

        } else if (key > root->val) {
            root->right = deleteNode(root->right, key); 
        } else {
            root->left = deleteNode(root->left, key);
        }
    }  
    return root;
}


int main () {

}