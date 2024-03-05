#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<ll, ll>
#define X first
#define Y second
#define PB push_back


vector<vector<ii>> adj;
const ll INF = 1e17 + 8;
bool spfa(ll s, vector<ll>& d) {
    ll n = adj.size();
    d.assign(n, INF);
    vector<ll> cnt(n, 0);
    vector<bool> inqueue(n, false);
    queue<ll> q;

    d[s] = 0;
    q.push(s);
    inqueue[s] = true;
    while (!q.empty()) {
        ll v = q.front();
        q.pop();
        inqueue[v] = false;

        for (auto edge : adj[v]) {
            ll to = edge.first;
            ll len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                if (!inqueue[to]) {
                    q.push(to);
                    inqueue[to] = true;
                    cnt[to]++;
                    if (cnt[to] > n)
                        return false;  // negative cycle
                }
            }
        }
    }
    return true;
}

bool multiTest = false;

void solve(){
    ll n, m, s, t, u, v, c, p;
    cin >> n >> m >> s >> t;
    adj.resize(n+7);
    vector<ll> arr(n);
    for (ll i = 0; i < m; i++){
        cin >> u >> v >> c;
        adj[u-1].push_back({v-1, c});
    }
    for (ll i = 0; i < n; i ++){
        cin >> arr[i];
    }
    for (ll i = 0; i < n; i++){
        for (int j = 0; j < adj[i].size(); j++){
            auto [v, c] = adj[i][j];
            adj[i][j] = {v, c - arr[i]};
        }
    }
    vector<ll> dist;
    bool cicle = spfa(s, dist);
    if (cicle){
        cout << "Money hack!" << endl;
    }else{
        if (dist[t] == INF) cout << "Bad trip" << endl;
        else cout << dist[t] << endl;
    }   

}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1;
    if (multiTest) cin >> t;
    while(t--){
        solve();
    }
    return 0;
    
}