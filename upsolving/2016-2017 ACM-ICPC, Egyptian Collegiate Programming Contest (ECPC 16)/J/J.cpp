#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<ll, ll>
#define X first
#define Y second
const ll ms = 5e5 + 7;
vector<ll> dad;
vector<ll> visited;
vector<ll> fuel;
vector<ll> ans;
vector<vector<ii>> adj;
set<ii> used;

ll dfs (ll u, ll cost){
    used.insert({cost, u});

    for (auto [nb, peso] : adj[u]){
        if (not visited[nb]){
            visited[nb] = true;
            dad[nb] = u;
            ans[u] += dfs(nb, cost + peso);
        }
    }
    ii aux = make_pair(cost - fuel[u], LLONG_MIN);
    auto it = used.lower_bound(aux);
    if (it == used.end()) return (10/0);
    if (it != used.begin()){
        auto [_, close] = *it;
        ans[dad[close]]--;
    }
    used.erase({cost, u});

    return (ans[u] + 1);

}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    //freopen("car.in","r",stdin);

    ll t; cin >> t;
    while (t--){
        ll n; cin >> n;
        used = {};
        dad.assign(n + 7, 0);
        ans.assign(n + 7, 0);
        fuel.assign(n + 7, 0);
        visited.assign(n + 7, false);
        adj.assign(n + 7, {});

        for (ll i = 0; i < n; i++){
            cin >> fuel[i];
        }
        for (ll i = 0; i < n - 1; i++){
            ll x, y, peso;
            cin >> x >> y >> peso;
            x--; y--;

            adj[x].push_back({y, peso});            
        }
        dfs(0,0);
        for (ll i = 0; i < n; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    
        
    return 0;
    
}