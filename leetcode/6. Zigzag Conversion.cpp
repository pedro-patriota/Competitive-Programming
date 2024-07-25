#include <bits/stdc++.h>
using namespace std;

string convert(string s, int numRows) {
    vector<vector<char>>table(numRows);
    int level = 0;
    bool down = true;
    if (numRows == 1) {
        return s;
    }
    for (auto letter : s) {
        table[level].push_back(letter);
        if (down) {
            level++;
        } else {
            level--;
        }
        if (level == numRows -1 || level == 0) {
            down = !down;
        }
    }
    string ans = "";
    for (auto depth : table) {
        for (auto letter : depth) {
            ans += letter;
        }
    }
    return ans;
}