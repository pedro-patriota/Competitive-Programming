#include <bits/stdc++.h>
using namespace std;

/*

[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]

-> wertf
*/

unordered_map<char, unordered_set<char>> adj;
unordered_map<char, int> in;

string topoSort() {
    string ans = "";
    queue<char> q;
    for (auto [l, freq] : in) {
        if (freq == 0) {
            q.push(l);
        }
    }
    while (not q.empty()) {
        int sz = q.size();
        while (sz--) {
            auto l = q.front();
            ans.push_back(l);
            q.pop();

            for (auto nh : adj[l]) {
                if (--in[nh] == 0) {
                    q.push(nh);
                }
            }
        }
    }

    return ans;
}

string findOrder(vector<string>& arr) {
    int sz = arr.size(), str_sz;
    char l, next_l, below_l;
    for (auto s : arr) {
        for (auto l : s) {
            in[l] = 0;
        }
    }
    for (int i = 0; i < sz; i++) {
        str_sz = arr[i].size();
        for (int j = 0; j < str_sz; j++) {
            l = arr[i][j];
            if (i < sz -1 && j < arr[i+1].size()) {
                below_l = arr[i+1][j];
                if (l != below_l) {
                    adj[l].insert(below_l);
                    in[below_l]++;
                    break;
                } 
            }
        }
    }

    string ans = topoSort();
    if (ans.size() != in.size()) {
        return "";
    }
    return ans;
}

int main() {
    vector<string> arr = {
        "z",
        "x",
        "z"
    };
    cout << findOrder(arr); 

}