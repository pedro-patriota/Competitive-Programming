#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll m, n, p1, p2, counter;
vector<vector<ll>> adj;
vector<vector<ll>> directed_adj;
map<ll, ll> pr;
vector<ll> indegree;
vector<bool> visited;
set<ll> items;

void dfs(ll u){
    for (auto i : adj[u]){
        if (!visited[i]){
            visited[i] = true;
            dfs(i);
            counter *= 2;
        }
    }
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    adj = vector<vector<ll>>(n);
    pr = map<ll, ll>();
    visited = vector<bool>(n, false);
    items = set<ll>();
    
    counter = 1;
    for (ll i = 0; i < m; i++)
    {
        cin >> p1 >> p2;
        p1--;
        p2--;
        if (not items.count(p1)){
            items.insert(p1);
        }
        if (not items.count(p2)){
            items.insert(p2);

        }
        adj[p1].push_back(p2);
        adj[p2].push_back(p1);
    }
    for (auto val : items){
        if (!visited[val]){
            visited[val] = true;
            dfs(val);
        }
    }
    

    cout << counter;
}