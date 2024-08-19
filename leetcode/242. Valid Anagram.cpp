#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
    unordered_map<char, int> freq_s;
    unordered_map<char, int> freq_t;

    for (auto letter : s) {
        freq_s[letter]++;
    }
    for (auto letter : t) {
        freq_t[letter]++;
    }
    if (freq_s.size() != freq_t.size()) {
        return false;
    }
    
    for (auto [letter, freq] : freq_s) {
        if (!freq_t.count(letter) || freq_t[letter] != freq) {
            return false;
        } 
    }
    return true;
}
