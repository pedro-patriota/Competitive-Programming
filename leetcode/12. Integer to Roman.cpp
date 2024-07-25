#include <bits/stdc++.h>
using namespace std;

string intToRoman(int num) {
    int base = 1000, div;
    string ans = "";
    unordered_map<int, string> table;
    table[1] = "I";
    table[5] = "V";
    table[10] = "X";
    table[50] = "L";
    table[100] = "C";
    table[500] = "D";
    table[1000] = "M";
    while (base > 0) {
        div = num/base;
        if (div == 4 || div == 9) {
            ans += table[base] + table[(div+1)*base];
        } else {
            if (div >= 5) {
                ans += table[base*5];
                div -= 5;
            }
            while (div--) {
                ans += table[base];
            }
        }
        num %= base;
        base /= 10;
    }
    return ans;
}
