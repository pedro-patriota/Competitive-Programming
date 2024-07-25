#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    string ans = "", word = "";
    s += " ";
    for (auto letter : s) {
        if (letter == ' ') {
            if (word != "") {
                ans = word + ' ' + ans;
                word = "";
            }
        } else {
            word += letter;
        }
    }   
    ans.pop_back();
    return ans;
}
