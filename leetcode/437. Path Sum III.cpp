#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

int traversal(TreeNode* root, int targetSum, unordered_map<long long, int>& prefix_path, long long prefix) {
    long long ans = 0, val, sz = prefix_path.size(), new_prefix;
    if (root != nullptr) {
        val = root->val;
        new_prefix = prefix + val;

        long long outter_path = new_prefix - targetSum;
        if (prefix_path.count(outter_path)) {
            ans += prefix_path[outter_path];
        }
        
        prefix_path[new_prefix]++;

        ans += traversal(root->left, targetSum, prefix_path, new_prefix);
        ans += traversal(root->right, targetSum, prefix_path, new_prefix);

        
        if (--prefix_path[new_prefix] == 0) {
            prefix_path.erase(new_prefix);
        }
    }
    return ans;
}

int pathSum(TreeNode* root, int targetSum) {
    unordered_map<long long, int> prefix_path;
    prefix_path[0]++;
    return traversal(root, targetSum, prefix_path, 0);
}


int main () {

}