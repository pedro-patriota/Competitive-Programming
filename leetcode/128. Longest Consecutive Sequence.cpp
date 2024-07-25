#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_map<int, int> longest_seq;
    int ans = 1;
    for (auto v : nums) {
        longest_seq[v] = 1;
    }    
    for (auto v : nums) {
        if (longest_seq[v] == 1) {
            int next = v -1;
            while (longest_seq.count(next) && longest_seq[next] != 0) {
                longest_seq[v] += longest_seq[next];
                longest_seq[next] = 0;
                ans = max(ans, longest_seq[v]);
                next--;
            }
        }
    }
    return ans;
}
