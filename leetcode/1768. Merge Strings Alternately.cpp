#include <bits/stdc++.h>
using namespace std;

bool multiTest = false;

string mergeAlternately(string word1, string word2) {
    bool is1Turn = true;
    int l, r, sz1, sz2;
    
    string ans = "";
    l = r = 0;
    sz1 = word1.size();
    sz2 = word2.size();
    while (l < sz1 || r < sz2) {
        if (is1Turn) {
            ans += word1[l];
            l++;

            if (r < sz2) {
                is1Turn = false;
            }

        }else {
            ans += word2[r];
            r++;

            if (l < sz1) {
                is1Turn = true;
            }
        }
    }

    return ans;
}
