#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

int traversal(TreeNode* root, int max_path) {
    int ans = 0;
    if (root != nullptr) {
        int val = root->val, max_val = max(max_path, val); 

        ans += traversal(root->left, max_val);
        ans += traversal(root->right, max_val);

        if (val >= max_path) {
            ans++;
        }

    }
    return ans;
}

int goodNodes(TreeNode* root) {
    return traversal(root, -1e9); 
}


int main () {

}