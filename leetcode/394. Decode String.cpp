#include <bits/stdc++.h>
using namespace std;

/*

ab2[ca3[d]]e


2

ddd

ca
ab


*/

string recDecodeString(string s, string pattern, int& pos) {
    if (pos == s.size()) {
        return pattern;
    }
    string num = "", rep_pattern;
    int int_num;
    for (; pos < s.size(); pos++) {
        if (isalpha(s[pos])) {
            pattern += s[pos];
        } else if (isdigit(s[pos])) {
            num += s[pos];
        } else if (s[pos] == '[') {
            int_num = stoi(num);
            num = "";
            pos++;
            rep_pattern = recDecodeString(s, "", pos); 

            for (int i = 0; i < int_num; i++) {
                pattern += rep_pattern;
            }

        } else {
            break;
        }
    }
    return pattern;
}

string decodeString(string s) {
    int pos = 0;
    return recDecodeString(s, "", pos);
}

int main () {

}