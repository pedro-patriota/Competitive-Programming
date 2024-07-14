#include <bits/stdc++.h>
using namespace std;
    
unordered_map<string, unordered_map<string, double>> adj;
unordered_set<string> var;

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    string from, to;
    for (int i = 0; i < equations.size(); i++) {
        var.insert(equations[i][0]);
        var.insert(equations[i][1]);
        adj[equations[i][0]][equations[i][1]] = values[i];
        adj[equations[i][1]][equations[i][0]] = (double) 1/values[i];
    }
    for (auto k : var) {
        for (auto i : var) {
            for (auto j : var) {
                if (adj[i].count(k) && adj[k].count(j)) {
                    adj[i][j] = max(adj[i][j], adj[i][k] * adj[k][j]);
                }
            }
        }
    }    
    vector<double> ans (queries.size());
    for (int i = 0; i < queries.size(); i++) {
        from = queries[i][0];
        to = queries[i][1];
        if (adj[from].count(to)) {
            ans[i] = adj[from][to];
        } else {
            ans[i] =  -1;
        }
    }
    return ans;

}
