#include <bits/stdc++.h>
using namespace std;

bool is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u'; 
}

int maxVowels(string s, int k) {
    int cnt = 0, mx;
    for (int i = 0; i < k; i++) {
        cnt += is_vowel(s[i]);
    }  
    mx = cnt;
    for (int right = k; right < s.size(); right++) {
        cnt += is_vowel(s[right]);
        cnt -= is_vowel(s[right - k]);

        mx = max(cnt, mx);
    }

    return mx;
}

int main () { 
    
}