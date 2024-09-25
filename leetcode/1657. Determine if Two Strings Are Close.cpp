#include <bits/stdc++.h>
using namespace std;

bool closeStrings(string word1, string word2) {
    vector<int> freq1(26, 0);
    vector<int> freq2(26, 0);

    for (auto v : word1) {
        freq1[v-'a']++;
    }
    for (auto v : word2) {
        if (freq1[v-'a'] == 0) {
            return false;
        }
        freq2[v-'a']++;
    }
    sort(freq1.begin(), freq1.end());
    sort(freq2.begin(), freq2.end());
    
    return freq1 == freq2;
}

int main () {

}