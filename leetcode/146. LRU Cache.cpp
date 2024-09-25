#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    int index;
    Node* next;
    Node* prev;
};

class LRUCache {
    public:
        int sz;
        unordered_map<int, Node*> node_hash;
        Node* head;
        Node* tail;

        Node* createNode(int val, int index) {
            Node* new_node = new Node;
            new_node->val = val;
            new_node->index = index;
            new_node->next = nullptr;
            new_node->prev = nullptr;

            return new_node;
        }
        void deleteNode(Node* prev) {
            if (prev == nullptr) {
                auto new_head = head -> next;

                delete head;
                head = new_head;
                if (head) {
                    new_head->prev = nullptr;
                }

            } else {
                auto to_delete = prev->next;
                if (to_delete->next) {
                    to_delete->next->prev = prev;
                } 
                prev->next = to_delete->next;
                if (to_delete == tail) {
                    tail = prev;

                }
                delete to_delete;
            }
        }
        Node* insertTop(int val, int index) {
            auto node = createNode(val, index);
            if (head == nullptr) {
                head = node;
                tail = node;
            } else {
                node->next = head;
                head->prev = node;
                head = node;
            }
            return node;
        }
        
        LRUCache(int capacity) {
            head = tail = nullptr;
            sz = capacity;
        }
        
        int get(int key) {
            int ans = -1;
            if (node_hash.count(key)) {
                auto node = node_hash[key];
                ans = node->val;

                deleteNode(node->prev);
                node = insertTop(ans, key);
                node_hash[key] = node;            
            }
                
            return ans;
        }
        
        void put(int key, int value) {

            if (node_hash.count(key)) {
                auto node = node_hash[key];
                deleteNode(node->prev);
                node = insertTop(value, key);
                node_hash[key] = node;    
            } else {
                if (node_hash.size() == sz) {
                    int to_delete_key = tail->index;
                    node_hash.erase(to_delete_key);
                    deleteNode(tail->prev);
                }
                auto node = insertTop(value, key);
                node_hash[key] = node;
            }
        }
};

int main () {

}