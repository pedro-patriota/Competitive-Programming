#include <bits/stdc++.h>
using namespace std;

/*
"The quick brown fox jumps over the dog"
Output: False

"The quick brown fox jumps over the lazy dog"
Output: True

lowercase = uppercase letters

"QWERTYUIOPASDFGHJKLZXCVBNM"
Output: True

"qwertyuio ! # . pasdfg/hjklzxcvbnm"
Output: True

"qwertyuiopasdfghjklzxcvbnm"
Ouput: False

""
Output: False

1. Go thourgh the string
2. Lowercase each letter
3. Check if it is an alphabet letter 
4. Insert in a hash set
5. Count if hash size == 26
Time: O(n)
Space: O(1)
*/

bool isPangrams(string s) {
    unordered_set<char>sentence_alphabet;
    for (auto letter : s) {
        char lowered_letter = tolower(letter);
        if (lowered_letter >= 'a' && lowered_letter <= 'z') {
            sentence_alphabet.insert(lowered_letter);
        }
    }
    return sentence_alphabet.size() == 26;
}

int main () {
    cout << "Expected: 0 / Got: " << isPangrams("The quick brown fox jumps over the dog") << endl;
    cout << "Expected: 1 / Got: " << isPangrams("The quick brown fox jumps over the lazy dog") << endl;
    cout << "Expected: 1 / Got: " << isPangrams("QWERTYUIOPASDFGHJKLZXCVBNM") << endl;
    cout << "Expected: 1 / Got: " << isPangrams("qwertyuiopasdfghjklzxcvbnm") << endl;
    cout << "Expected: 0 / Got: " << isPangrams("") << endl;
    cout << "Expected: 1 / Got: " << isPangrams("qwertyuio ! # . pasdfg/hjklzxcvbnm") << endl;
}