#include <bits/stdc++.h>
using namespace std;

/*

sssi

ssi

*/

int strStr(string haystack, string needle) {
    int beg = 0, curr = 0, sz_haystack = haystack.size(), sz_needle = needle.size();
    if (sz_needle > sz_haystack) {
        return -1;
    }
    for (int i = 0; i <= sz_haystack - sz_needle; i++) {
        if (haystack.substr(i, sz_needle) == needle) {
            return i;
        }
    }
    return -1;
}
