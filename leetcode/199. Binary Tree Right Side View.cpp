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

int level = 0;
void traversal(TreeNode* root, vector<int>& ans, int lv) {
    if (root) {
        if (lv == level) {
            ans.push_back(root->val);
            level++;
        }
        traversal(root->right, ans, lv + 1);
        traversal(root->left, ans, lv + 1);
    }
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    traversal(root, ans, 0);
    return ans;
}