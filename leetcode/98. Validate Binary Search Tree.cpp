#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

long long last_v = LLONG_MIN;
bool ans = true;

void traversal(TreeNode* root) {
    if (root) {
        traversal(root->left);
        if (root->val <= last_v) {
            ans = false;
            return;
        }
        last_v = root->val;
        traversal(root->right);
    } 
}

bool isValidBST(TreeNode* root) {
    traversal(root);

    return ans;
}

int main()
{
   
    return 0;
}