#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* ans;

TreeNode* traversal(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root) {
        auto left = traversal(root->left, p, q);
        auto right = traversal(root->right, p, q);
        set<TreeNode> s;
        s.(left);
        s.insert(right);
        s.insert(root);

        if (s.count(p) && s.count(q)) {
            ans = root;
        }

        if (left == p || left == q) {
            return left;
        }
        if (right == p || right == q) {
            return right;
        }


    }
    return root;
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    traversal(root, p, q);
    return ans;
}