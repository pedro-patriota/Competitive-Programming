#include <bits/stdc++.h>
using namespace std;

int sz;
string pal, ans = "";
void expandPal(int left, int right, string& s) {

    while (left >= 0 && right < sz && s[left] == s[right]) {
        pal = s.substr(left, right - left + 1);
        if (pal.size() > ans.size()) {
            ans = pal;
        }
        left--;
        right++;
    }
}

string longestPalindrome(string s) {
    sz = s.size();
    for (int i = 0; i < sz; i++) {
        expandPal(i, i, s);
        expandPal(i-1, i, s);
    }
    return ans;
}
