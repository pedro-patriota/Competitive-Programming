#include <bits/stdc++.h>
using namespace std;
/*
Input: nums = [-10,-3,0,5,9]
-> try make a balanced tree

    0
 -3    5
-10      9

    0
 -10   5
    -3   9

empty => V
many heigth balanced => V
nums < 1e4

nums = [1, 1, 4, 12, 12, 15]

                4
            1      12
        1        12   15

0 1   2       
1, 1, 4, 12, 12, 15
^                
1 1

            4
        1      12
          1   12   15

if (low > high) return nullptr
pivot = createNode(data)
pivot -> left = convertToBST(low, pivot)
pivot -> right = convertToBST(pivot, high)
return pivot

*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* createsNode(int val) {
    TreeNode* new_node =  new TreeNode;
    new_node->val = val;
    new_node->left = nullptr;
    new_node->right = nullptr;

    return new_node;
}

TreeNode* convertToBst(vector<int>& arr, int low, int high) {
    if (low <= high) {

        int pivot_index = (high + low)/2;
        auto pivot = createsNode(arr[pivot_index]);
        pivot->left = convertToBst(arr, low, pivot_index - 1);
        pivot->right = convertToBst(arr, pivot_index + 1, high);
         return pivot;
    } 
    return nullptr;

}

void printTree(TreeNode* head) {
    if (head) {
        cout << head->val << " ";
        printTree(head->left);
        printTree(head->right);
    }
}
 
int main () {
    vector<int> arr = {-10,-3,0,5,9};
    auto head = convertToBst(arr, 0,arr.size() - 1);
    printTree(head);
    cout << endl;
    arr = {1, 1, 4, 12, 12, 15};
    head = convertToBst(arr, 0,arr.size() - 1);
    printTree(head);
}