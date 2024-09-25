#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    private:
        Node* createNode(int val);
        Node* tail = nullptr;
        Node* head = nullptr;
    public:
        void insertVal(int val);
        int popLinkedList();
        int popVal(int val);
        void printLinkedList();
};

Node* LinkedList :: createNode(int val) {
    Node* new_node = new Node;
    new_node->data = val;
    new_node->next = nullptr;

    return new_node;
}

void LinkedList :: insertVal(int val) {
    auto next_node = createNode(val);
    if (head == nullptr) {
        tail = head = next_node;
    } else {
        tail->next = next_node;
        tail = tail->next;
    }
} 

int LinkedList :: popLinkedList() {
    Node* prev =  head;
    if (tail == head) {
        tail = head = nullptr;
        return head->data;
    }
    while(prev != nullptr && prev->next != tail) {
        prev = prev->next;
    }
    tail = prev;
    tail->next = nullptr;

    return tail->data;
}   

int LinkedList :: popVal(int val) {
    Node* prev = head;
    if (val == head->data) {
        head = head->next;
        return val;
    }
    while(prev->next != nullptr && prev->next->data != val) {
        prev = prev->next;
    }
    prev->next = prev->next->next;
    return val;
}

void LinkedList :: printLinkedList() {
    Node* node = head;
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    LinkedList ll;
    ll.insertVal(1);
    ll.insertVal(3);
    ll.insertVal(4);
    ll.printLinkedList();
    ll.popVal(3);
    ll.printLinkedList();
    ll.popLinkedList();
    ll.printLinkedList();
}