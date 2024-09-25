#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};

void insertNodes(ListNode* node, stack<int>& stack_node) {
    if (node != nullptr) {
        stack_node.push(node->val);
        insertNodes(node->next, stack_node);
    }
}
void findPair(ListNode* node, stack<int>& stack_node, int& ans) {
    if (node != nullptr) {
        ans = max(node->val, stack_node.top());
        stack_node.pop();
        findPair(node->next, stack_node, ans);
    }
}

int pairSum(ListNode* head) {
    stack<int> stack_node;
    int ans = 0;
    insertNodes(head, stack_node);
    findPair(head, stack_node, ans);
    return ans;
}

int main () {

}