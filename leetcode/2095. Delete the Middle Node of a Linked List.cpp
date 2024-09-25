#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    ListNode* next;
    int val;
};

/*
    0 1 2 null
l = 0 1 2 
r = 2 1 0

    0 1 null
l = 0 1
r = 1 0

*/
pair<ListNode*, int> traversal(ListNode* head, int left) {
    if (head != nullptr) {
        auto [pt, right] = traversal(head->next, left + 1);
        if (abs(right - left) <= 1) {
            return {pt, 1e9};
        }
        head->next = pt;
        return {head, right+1};
        
    } 
    return {head, 0};
}

ListNode* deleteMiddle(ListNode* head) {
    return traversal(head, 0).first;
}

int main () {

}