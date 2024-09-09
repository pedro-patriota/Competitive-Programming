#include <bits/stdc++.h>
using namespace std;
/*
Input: chars = ['a','a','b','b','c','c','c']
Output: Return 6, and the first 6 characters of the input array should be: ['a','2','b','2','c','3']
Explanation: The groups are 'aa', 'bb', and 'ccc'. This compresses to 'a2b2c3'.

Input: chars = ['a']
Output: Return 1, and the first character of the input array should be: ['a']
Explanation: The only group is 'a', which remains uncompressed since it's a single character.

Input: chars = ['a','b','b','b','b','b','b','b','b','b','b','b','b']
Output: Return 4, and the first 4 characters of the input array should be: ['a','b','1','2'].
Explanation: The groups are 'a' and 'bbbbbbbbbbbb'. This compresses to 'ab12'.

'/', '/', 'A', 'A', 'c'
/2A2c
->5

'a', 'b', 'c', 'a', 'b'
abcab
-> 5

1 Approach
cnt = 3
ans = 1 + 1 = 2 -> 2 + (1 + 1) -> 4 + ( 1+ 1) -> 6

ans ++;
if cnt > 1
  ans += ctn/10 + 1

'a','a','b','b','c','c','c'
                           ^

cnt = 1
ans = 5

'a', 'b', 'c', 'a', 'b'
                        ^

time: O(N)
space: O(1)

*/

    int compress(vector<char>& chars) {
        int cnt = 1, ans = 0, sz = chars.size();
        for (int i = 1; i < sz; i++) {
            if (chars[i] != chars[i-1]) {
                chars[ans] = chars[i-1];
                ans++;
                if (cnt > 1) {
                    for (auto d : to_string(cnt)) {
                        chars[ans] = d;
                        ans++;
                    }
                }
                cnt = 1;
            } else {
                cnt++;
            }
        }
        chars[ans] = chars[sz -1];
        ans++;
        if (cnt > 1) {
            for (auto d : to_string(cnt)) {
                chars[ans] = d;
                ans++;
            }
        }

        return ans;
}


int main () {
    vector<char> chars = {'a','a','b','b','c','c','c'};
    cout << compress(chars) << endl; // 6

    chars = {'a'};
    cout << compress(chars) << endl; // 1

    chars = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    cout << compress(chars) << endl; // 4

    chars = {'/', '/', 'A', 'A', 'c'};
    cout << compress(chars) << endl; // 5

    chars = {'a', 'b', 'c', 'a', 'b'};
    cout << compress(chars) << endl; // 5
}
