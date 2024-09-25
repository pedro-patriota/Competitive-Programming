#include <bits/stdc++.h>
using namespace std;

/*
a a a a a a a

O(n)
O(1)

b -> aa
c -> bb

b -> 2a
c -> 4a
d -> 8a


size = 7
cba

111

a a a a 
size = 4
c
100

""
size = 0
000

a
size = 1
001

size = 26^2

time: O(logN)
space: O(1)

*/

string uniteString(string s) {
    int sz = s.size(), num_z, z_index = 25;
    string ans = "";
    
    for (int bit = 31; bit >= 0; bit--) {
        bool bit_val = (1 << bit) & sz;  

        if (bit_val) {
            if (bit >= z_index) {
                num_z = 1 << (bit - z_index);
                while (num_z--) {
                    ans.push_back('z');
                }
            } else {
                ans.push_back((char) ('a' + bit));
            }
        }
    }
    return ans;
}

int main () {
    cout << uniteString("aaaaaaa");

}