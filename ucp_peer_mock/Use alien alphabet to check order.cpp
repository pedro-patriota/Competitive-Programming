#include <bits/stdc++.h>
using namespace std;


bool checkOrder(vector<string>& order, string alphabet) {
    unordered_map<char, int> alphabet_order;

    int alphabet_sz = alphabet.size();
    for (int i = 0; i < alphabet_sz; i++) {
        alphabet_order[alphabet[i]] = i;
    }

    int order_sz = order.size();
    for (int i = 1; i < order_sz; i++) {
        string after_str = order[i];
        string past_str = order[i-1];
        
        int mn_sz = min(after_str.size(), past_str.size());
        bool found_dir = false;
        for (int j = 0; j < mn_sz; j++) {
            if (after_str[j] != past_str[j]) {
                if (alphabet_order[after_str[j]] < alphabet_order[past_str[j]]) {
                    return false;
                }
                found_dir = true;
                break;
            }
        }
        if (past_str.size() > after_str.size() && not found_dir) {
            return false;
        }
    }

    return true;
}

int main () {
    vector<string> order = {"word", "world", "row"};
    string alphabet = "worldabce";
    cout << checkOrder(order, alphabet) << endl; // 0

    order = {"hello", "uber"};
    alphabet = "huabcdefgijklmnpqstuvxyz";
    cout << checkOrder(order, alphabet) << endl; // 1
    
    order = {"helloo", "hello"};
    alphabet = "huabcdefgijklmnpqstuvxyz";
    cout << checkOrder(order, alphabet) << endl; // 0
    

}