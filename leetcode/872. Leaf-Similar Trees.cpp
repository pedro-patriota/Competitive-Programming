#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

void traversal(TreeNode* root, vector<int>& ans) {
    if (root != nullptr) {
        traversal(root->left, ans);
        ans.push_back(root->val);
        traversal(root->right, ans);
    }
}

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> ans1, ans2;
    traversal(root1, ans1);
    traversal(root2, ans2);
    return ans1 == ans2;
}

int main () {

}