#include <bits/stdc++.h>
using namespace std;

bool one_diff(string s1, string s2) {
    int cnt = 0;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) {
            cnt++;
        }
    }
    return cnt == 1;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_map<string, unordered_set<string>> adj;
    unordered_set<string> vis;
    bool has_end = false;
    for (auto s1 : wordList) {
        if (one_diff(beginWord, s1)) {
            adj[beginWord].insert(s1);
            adj[s1].insert(beginWord);
        }
    }
    if (not adj.count(endWord)) {
        return 0;
    }
    for (auto s1 : wordList) {
        for (auto s2 : wordList) {
            if (one_diff(s1, s2)) {
                adj[s1].insert(s2);
                adj[s2].insert(s1);
            }
        }
    }
    queue<string> q;
    q.push(beginWord);
    vis.insert(beginWord);
    int ans = 0;
    while (not q.empty()) {
        ans++;
        int sz = q.size();
        while (sz--) {
            auto s = q.front();
            q.pop();

            for (auto nh : adj[s]) {
                if (not vis.count(nh)) {
                    if (nh == endWord) {
                        return ans;
                    }
                    vis.insert(nh);
                    q.push(nh);
                }
            }
        }
    }
    return 0;

}

int main () {

}
