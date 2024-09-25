#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};


ListNode* reverse(ListNode* head, ListNode* new_head) {
    if (head != nullptr) {
        auto pt = reverse(head->next, new_head);
        head->next = nullptr;
        if (pt != nullptr) {
            cout << pt->val << endl;
            pt->next = head;
        } else {
            new_head = head;
        }
    } 
    return head;
}

ListNode* reverseList(ListNode* head) {
    auto _ = reverse(head, head);
    return head;
}

int main () {
    
}