#include <bits/stdc++.h>
using namespace std;

/*V1 
Time: O(N^2)
Space: O(N^2)

int cnt;
bool one_diff(string s1, string s2) {
    cnt = 0;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) {
            cnt++;
        }
        if (cnt > 1)
            return false;
    }
    return true;
}

int ladderLength(string beginWord, string endWord,
                    vector<string>& wordList) {
    unordered_map<string, unordered_set<string>> adj;
    unordered_set<string> vis;
    for (auto s1 : wordList) {
        if (one_diff(beginWord, s1)) {
            adj[beginWord].insert(s1);
            adj[s1].insert(beginWord);
        }
    }
    string s1, s2;
    for (int i = 0; i < wordList.size(); i++) {
        s1 = wordList[i];
        for (int j = i +1; j < wordList.size(); j++) {
            s2 = wordList[j];
            if (one_diff(s1, s2)) {
                adj[s1].insert(s2);
                adj[s2].insert(s1);
            }
        }
    }
    if (not adj.count(endWord)) {
        return 0;
    }
    queue<string> q;
    q.push(beginWord);
    vis.insert(beginWord);
    int ans = 1, sz;
    string s;
    while (not q.empty()) {
        ans++;
        sz = q.size();
        while (sz--) {
            s = q.front();
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
*/

/*
a b c d e
  ^
*/
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    wordList.push_back(beginWord);
    int ans = 1, sz = wordList.size(), word_sz = wordList[0].size();
    string pattern;
    unordered_map<string, unordered_set<string>> pattern_hash;
    unordered_map<string, unordered_set<string>> adj;
    unordered_set<string> vis;

    bool has_end_word = false;
    for (int i = 0; i < sz; i++) {
        if (wordList[i] == endWord) {
            has_end_word = true;
        }
        for (int div = 0; div < word_sz; div++) {
            pattern = wordList[i].substr(0, div) + "*" + wordList[i].substr(min(div + 1, word_sz -1), word_sz - 1 - div);
            pattern_hash[pattern].insert(wordList[i]);
        }
    }
    if (not has_end_word) {
        return 0;
    }
    for (int i = 0; i < sz; i++) {
        for (int div = 0; div < word_sz; div++) {
            pattern = wordList[i].substr(0, div) + "*" + wordList[i].substr(min(div + 1, word_sz -1), word_sz - 1 - div);
            for (auto s : pattern_hash[pattern]) {
                if (s != wordList[i]) {
                    adj[wordList[i]].insert(s);
                }
            }
        }
    }

    queue<string> q;
    vis.insert(beginWord);
    q.push(beginWord);
    while (not q.empty()) {
        int sz = q.size();
        while (sz--) {
            string s = q.front();
            q.pop();

            if (s == endWord) {
                return ans;
            }
            for (auto nh : adj[s]) {
                if (not vis.count(nh)) {
                    q.push(nh);
                    vis.insert(nh);
                }
            }


        }
        ans++;  
    }
    return 0;
}


int main () {
    vector<string> input = {"hot","dot","dog","lot","log","cog"};
    cout << ladderLength("hit", "cog", input);
}
