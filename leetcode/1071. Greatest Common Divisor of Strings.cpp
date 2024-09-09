#include <bits/stdc++.h>
using namespace std;

/*
Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"

Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"

Input: str1 = "LEET", str2 = "CODE"
Output: ""

"" "ADC"
""

"CODE" "CODED"
""

1 Approach
Divide the each string for each divisor


2 Approach
Check all substrings in the smallest string
    check if it can be repeaetd in the other

N = str1.size
M = str2.size
Time: O(min(N,M)*(min(N,M) + N + M))

3 Aprroach 
If there is gcd string 
-> then str1 + str2 == str2 + str1
str1 = t + t
str2 = t + t + t

str1 + str2 = t + t+ t+ t+ t+
str2 + str2 = t + t+ t+ t+ t+
str1 = t + t
str2 = t + t

gcd(str1.size, str2.size)


*/

string gcdOfStrings(string str1, string str2) {
    if (str1 + str2 == str2 + str1) {
        return str1.substr(0, __gcd(str1.size(), str2.size()));
    }
    return "";
}

// string gcdOfStrings(string str1, string str2) {
//     int sz1 = str1.size(), sz2 = str2.size();
//     string ans = "";
//     if (sz1 > sz2) {
//         return gcdOfStrings(str2, str1);
//     }
//     for (int i = 1; i <= sz1; i++) {
//         string sub = str1.substr(0, i);
//         int sub_size = sub.size(), beg = 0;
//         bool is_possible = true;

//         if (sz1 % sub_size == 0 && sz2 % sub_size == 0) {
//             while (str1.substr(beg, i) == sub && beg < sz1) {
//                 beg += i;
//             }
//             if (beg < sz1) {
//                 is_possible = false;
//             }
//             beg = 0;
//             while (is_possible && str2.substr(beg, i) == sub && beg < sz2) {
//                 beg += i;
//             }
//             if (beg < sz2) {
//                 is_possible = false;
//             }
//             if (is_possible) {
//                 ans = sub;
//             }
//         }
//     }
//     return ans;
// }

int main () {
    cout << gcdOfStrings("ABCABC", "ABC") << endl; // ABC
    cout << gcdOfStrings("ABABAB", "ABAB") << endl; // AB
    cout << gcdOfStrings("LEET", "CODE") << endl; // ""
    cout << gcdOfStrings("", "CODE") << endl; // ""
    cout << gcdOfStrings("CODED", "CODE") << endl; // ""
    cout << gcdOfStrings("CODED", "CODED") << endl; // "CODED"
}