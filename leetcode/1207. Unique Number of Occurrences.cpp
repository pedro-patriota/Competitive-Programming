#include <bits/stdc++.h>
using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> freq;
    unordered_set<int> freq_set;
    for (auto v : arr) {
        freq[v]++;
    }
    for (auto [_, f] : freq) {
        if (freq_set.count(f)) {
            return false;
        }
        freq_set.insert(f);
    }
    
    return true;
}

int main () {

}