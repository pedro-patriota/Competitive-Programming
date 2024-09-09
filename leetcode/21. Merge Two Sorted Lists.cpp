#include <bits/stdc++.h>
using namespace std;

/*
[]
[]
[]

1->2
[]
1->2

1->2->5
3->4->6
1 -> 2 -> 3 -> 4 -> 5 -> 6

-1->0->5
-2->6
-2 -> -1 -> 0 -> 5 -> 6

1->2->3
2->4
1->2->2->3->4

1->2->3
        ^

2->4
   ^

1-> 2 -> 2 -> 3 -> 4

time: O(N)
space: O(N)
*/

struct ListNode
{
    int val;
    ListNode* next;
};


ListNode* insert_at_back(ListNode* tail, int val) {
    ListNode* new_node = new ListNode;
    new_node -> next = nullptr;
    new_node -> val = val;
    tail -> next = new_node;
    
    return new_node;
}

void insert_and_move(ListNode*& tail, ListNode*& param_head) {
    tail = insert_at_back(tail, param_head->val);
    param_head = param_head->next;
}

ListNode* mergeTwoLinkedList(ListNode* head1, ListNode* head2) {
    ListNode* new_head = new ListNode;
    ListNode* tail = new_head;

    while (true) {
        if (head1 == nullptr && head2 == nullptr) {
            break;
        } else if (head1 == nullptr && head2 != nullptr) {
            insert_and_move(tail, head2);
        } else if (head2 == nullptr && head1 != nullptr) {
            insert_and_move(tail, head1);
        } else {
            if (head1->val < head2->val) {
                insert_and_move(tail, head1);
            } else {
                insert_and_move(tail, head2);
            }
        }
    }   
    return new_head->next;
}

void print_ll(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
}

int main () {
    ListNode* head1 = new ListNode;
    ListNode* head2 = new ListNode;
    auto tail1 = head1;
    auto tail2 = head2;

    tail1 = insert_at_back(tail1, 1);
    tail1 = insert_at_back(tail1, 4);
    tail1 = insert_at_back(tail1, 5);
    head1 = head1 ->next;

    tail2 = insert_at_back(tail2, 1);
    tail2 = insert_at_back(tail2, 3);
    tail2 = insert_at_back(tail2, 9);
    head2 = head2 ->next;
    print_ll(mergeTwoLinkedList(head1, head2));

}


