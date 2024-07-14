#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second
#define PB push_back

bool multiTest = false;

struct LinkedList {
    int data;
    LinkedList* right;
    LinkedList* left;
};

void add_right (int v, LinkedList* curr) {
    LinkedList* new_ll = new LinkedList;
    new_ll->data = v;
    new_ll->right = curr->right;
    new_ll -> left = curr;

    if (curr->right != nullptr) {
        curr->right->left = new_ll;
    }
    curr->right = new_ll;
}

void add_left (int v, LinkedList* curr) {
    LinkedList* new_ll = new LinkedList;
    new_ll->data = v;
    new_ll->left = curr->left;
    new_ll -> right = curr;

    if (curr->left != nullptr) {
        curr->left->right = new_ll;
    }
    curr->left = new_ll;
}

void delete_right(LinkedList* prev) {
    if (prev->right == nullptr) {
        return;
    }
    LinkedList* next_deleted = prev->right->right;
    delete prev->right;
    prev->right = next_deleted;
    if (next_deleted != nullptr) {
        next_deleted->left = prev;
    }
}

void delete_left(LinkedList* prev) {
    if (prev->left == nullptr) {
        return;
    }
    LinkedList* next_deleted = prev->left->left;
    delete prev->left;
    prev->left = next_deleted;
    if (next_deleted != nullptr) {
        next_deleted->right = prev;
    }
}

void print_ll(LinkedList* curr) {
    while (curr->left != nullptr) {
        curr = curr->left;
    }
    while (curr->right != nullptr) {
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << curr->data << " " << endl;
}



void solve() {
    LinkedList* head = new LinkedList;
    head->data = -1;
    head->right = nullptr;
    head->left = nullptr;

    add_right(2, head);
    add_right(1, head);
    add_left(4, head);
    add_left(3, head);
    print_ll(head);
    delete_left(head);
    print_ll(head);
    delete_left(head);
    print_ll(head);
    delete_right(head);
    print_ll(head);
    delete_right(head);
    print_ll(head);

}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1;
    if (multiTest)
        cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}