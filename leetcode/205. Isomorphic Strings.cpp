#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t) {
    unordered_map<char, char> table;
    int s_size = s.size(), t_size = t.size();
    if (s_size != t_size) {
        return false;
    }
    for (int i = 0; i < s_size; i++) {
        if (table.count(s[i]) && table[s[i]] != t[i]) {
            return false;
        }
        table[s[i]] = t[i];
    }
    return true;
}
