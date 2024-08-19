#include <bits/stdc++.h>
using namespace std;

/*
“egg”, “add”
True
e -> a
g -> d

“foo”, “bar”
False
f-> b
o -> a 
o -> r X

len(s1) != len(s2) -> false
"" "" -> True

uppercase != lowercase
characters may be differnt from the alphabet
“.egg#”, “^add/”
True

"for", "baa"
False
f -> b
o -> a
r -> a X

"foe", "rof"
True

"foeo", "roff"
False

1. Create two hashes (one for the left->rigth relation and other for the right->left relation)
2. Go through the string
    2.1 If there is no relation using s1 and s2, create one
    2.2 If there is, check if it is correct
    2.3 else return false
3. return true

time: O(n)
space: O(n)

egg 
   ^

add
   ^

h1: (e:a), (g:d)
h2: (a:e), (d:g)

for
  ^

baa
  ^

h1: (f:b), (o:a)
h2: (b:f), (a:o)

*/

bool isIsomorphic(string s1, string s2) {
    if (s1.size() != s2.size()) {
        return false;
    }
    unordered_map<char, char> relation_s1_to_s2;
    unordered_map<char, char> relation_s2_to_s1;
    for (int i = 0; i < s1.size(); i++) {
        char l1 = s1[i], l2 = s2[i];
        if (not relation_s1_to_s2.count(l1) && not relation_s2_to_s1.count(l2)) {
            relation_s1_to_s2[l1] = l2;
            relation_s2_to_s1[l2] = l1;
        } else if (relation_s1_to_s2.count(l1) && relation_s2_to_s1.count(l2)) {
            if (relation_s1_to_s2[l1] != l2 || relation_s2_to_s1[l2] != l1) {
                return false;
            }
        } else {
            return false;
        }
    }
    return true;
}

int main () {
    cout << "Expected: 1 / Got: " << isIsomorphic("egg", "add") << endl;
    cout << "Expected: 0 / Got: " << isIsomorphic("foo", "bar") << endl;
    cout << "Expected: 0 / Got: " << isIsomorphic("for", "baa") << endl;
    cout << "Expected: 1 / Got: " << isIsomorphic("foe", "rof") << endl;
    cout << "Expected: 0 / Got: " << isIsomorphic("foeo", "roff") << endl;
    cout << "Expected: 0 / Got: " << isIsomorphic("fooo", "bar") << endl;
    cout << "Expected: 1 / Got: " << isIsomorphic("", "") << endl;
    cout << "Expected: 1 / Got: " << isIsomorphic(".egg#", "^add/") << endl;
}