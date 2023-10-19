#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second

const int ms =  2e5 + 17;
bool multiTest = true;
int colors[ms], n;

int visited[ms], freq[ms], treeFreq[ms], sz[ms], visits, beg, ed;
vector<vector<int>> adj;
int dfs(int u){
    visited[u] = true;
    for (auto nh : adj[u]){
        if (not visited[nh]){
            sz[u] += dfs(nh);
        }
    }
    return sz[u];
}
void treeDfs(int u){
    visited[u] = true;
    treeFreq[colors[u]]++;
    for (auto nh : adj[u]){
        if (not visited[nh] && nh != ed){
           treeDfs(nh);
        }
    }
}

void solve(){
    cin >> n;
    bool isPos = true;
    if (n%2 == 1) isPos = false;
    visits = 0;

    for (int i = 0; i < n; i ++){
        freq[i] = 0;
        treeFreq[i] = 0;
        visited[i] = false;
        sz[i] = 1;
    }
    for (int i = 0; i < n; i++){
        cin >> colors[i]; colors[i]--;
        freq[colors[i]]++;
    }
    
    adj.assign(n, {});
    for (int i = 0; i < n - 1; i++){
        int n1, n2;
        cin >> n1 >> n2; n1--; n2--;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }
    for (int i = 0; i < n; i++) if (freq[i]%2 == 1) {
        isPos = false;
        break;
    }
    if (not isPos){
        cout << -1 << endl;
        return;
    }
    dfs(0); beg = -1;
    for (int i = 0; i < n; i++) if (sz[i] == n/2)
    {
        beg = i;
        break;
    }
    if (beg == -1){
        cout << -1 << endl;
        return;
    }
    
    for (auto nh : adj[beg]){
        if (sz[nh] > sz[beg]){
            ed = nh;
            break;
        }
    }
    for (int i = 0; i < n; i++) visited[i] = false;
    treeDfs(beg);
    int ans = 0;
    for (int color = 0; color < n; color ++){
        ans += abs(treeFreq[color] - freq[color]/2);
    }

    cout << ans/2 << endl;

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