#include <bits/stdc++.h>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> freq;
    for (auto letter : magazine) {
        freq[letter]++;
    }   
    for (auto letter : ransomNote) {
        if (--freq[letter] < 0) {
            return false;
        }
    }

    return true;
}
