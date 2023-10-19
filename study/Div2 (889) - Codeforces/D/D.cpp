#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<ll, ll>
#define X first
#define Y second

bool multiTest = true;
ll n;
const ll ms = 2e5 + 17;
ll arr[ms];
ll vis[ms];
ll sz[ms];
vector<ll> adj[ms];
ll ans[ms];

ll preCalc (ll u, ll  p){
    vis[u] = true;
    for (auto nh : adj[u]){
        if (not vis[nh]){
            sz[u] += preCalc(nh, u);
        }
    }
    if (p != -1){
        ans[0] += (ll) (arr[u] ^ arr[p])*sz[u];
    }
    return sz[u];
}

void calc(ll u, ll p, ll a){
    vis[u] = true;
    if (p != -1){
        a +=  ((n - sz[u])*(arr[u] ^ arr[p])) - (sz[u]*(arr[u] ^ arr[p]));
        ans[u] = a;
    }
    for (auto nh : adj[u]){
        if (not vis[nh]){
            calc(nh, u, a);
        }
    }
}


void solve(){
    cin >> n;
    for (ll i = 0; i < n; i++){
        ll v; cin >> v;
        adj[i] = {};
        arr[i] = v;
        ans[i] = 0;
        vis[i] = false;
        sz[i] = 1;
    }
    for (ll i = 0; i < n - 1; i++){
        ll v1, v2;
        cin >> v1 >> v2;
        v1--;v2--;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
    preCalc(0, -1);
    for (ll i = 0; i < n ; i ++) vis[i] = false;
    calc(0, -1, ans[0]);
    for (ll i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;


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