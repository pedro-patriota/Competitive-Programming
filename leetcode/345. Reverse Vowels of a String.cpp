#include <bits/stdc++.h>
using namespace std;

/*
Input: s = "hello"
Output: "holle"
e -> o

Input: s = "leetcode"
Output: "leotcede"
e->e
e->o

"bcdfg"
"bcdfg"

"/mal#o#"
"/mol#a#"

"helulo"
"holule"

"hElulO"
"hOlulE"

1 Approach
holule
   ^
   ^

leotcede
    ^
    ^
time: O(N)
space: O(1)
*/

string reverseVowels(string s) {
    int left = 0, right = s.size() - 1;
    unordered_set<char> vowels;
    vowels.insert('a');
    vowels.insert('e');
    vowels.insert('i');
    vowels.insert('o');
    vowels.insert('u');

    while (true) {
        while(left < right && not vowels.count(tolower(s[left]))) {
            left++;
        }
        while(left < right && not vowels.count(tolower(s[right]))) {
            right--;
        }
        if (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        } else {
            break;
        }
    }
    return s;
}

int main () {
    cout << reverseVowels("hello") << endl; // holle
    cout << reverseVowels("leetcode") << endl; // leotcede
    cout << reverseVowels("bcdfg") << endl; // bcdfg
    cout << reverseVowels("/mal#o#") << endl; // /mol#a#
    cout << reverseVowels("helulo") << endl; // holule
    cout << reverseVowels("hElulO") << endl; // hOlulE
}