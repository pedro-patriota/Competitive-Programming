#include <bits/stdc++.h>
using namespace std;

struct bst {
    bst* right;
    bst* left;
    int v;
};

bst* create_new_node (int v) {
    bst* node = new bst;
    node ->left = nullptr;
    node -> right = nullptr;
    node -> v = v;
    
    return node;
}

bst* insert_in_bst(bst* node, int v) {
    if (node == nullptr) {
        return create_new_node(v);
    }
    else if (v >= node->v) {
        node -> right = insert_in_bst(node -> right, v);
    }
    else {
        node -> left = insert_in_bst(node -> left, v);
    }

    return node;
}

bst* delete_in_bst(bst* node, int v) {
    if (node == nullptr) {
        return nullptr;
    }
    else if (v > node->v) {
        node -> right = delete_in_bst(node -> right, v);
    }
    else if (v < node->v){
        node -> left = delete_in_bst(node -> left, v);
    } else{
        bst* next_node;
        if (node->right == nullptr) {
            next_node = node ->left;
            delete node;
            return next_node;
        }
        if (node->left == nullptr) {
            next_node = node ->right;
            delete node;
            return next_node;
        }

        next_node = node->right;
        while (next_node && next_node -> left != nullptr){
            next_node = next_node->left;
        }

        node->v = next_node->v;
        node->right = delete_in_bst(node->right, next_node->v);

    }
    return node;
}

void in_order_bst(bst* node) {
    if (node -> left) {
        in_order_bst(node->left);
    }
    cout << "Node: " << node->v << endl;
    if (node -> right) {
        in_order_bst(node->right);
    }
}


int main () {
    auto head = insert_in_bst(nullptr, 10);
    insert_in_bst(head, 5);
    insert_in_bst(head, 15);
    insert_in_bst(head, 25);
    insert_in_bst(head, 12);
    in_order_bst(head);
    head = delete_in_bst(head, 10);
    in_order_bst(head);





    return 0;
}