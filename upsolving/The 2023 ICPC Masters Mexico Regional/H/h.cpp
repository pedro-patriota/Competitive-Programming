#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second
#define PB push_back

// Kosaraju

vector<vector<int>> G, Gt;
vector<int> id;
vector<int> order;
vector<bool> vis;
vector<int> colors;
int n;
int ans = 0;

vector<int> representants(c.size(), - 1);

void dfs_pos_scc(int v){
  vis[v] = true;
  bool has_nb = false;
  for(int u : G[v]){
    if(!vis[u] && colors[v] != colors[u]){
        has_nb = true;
        dfs_pos_scc(u);
    } 
  }
  if (not has_nb){
    ans++;
  } 
}

void dfs1(int v){ // ordem de saida 
  vis[v] = true;
  for(int u : G[v]){
    if(!vis[u]) dfs1(u);
  }
  order.PB(v);
}
void dfs2(int v, int idx, vector<int>& component){ // pegar um componente todo
    vis[v] = true;
    id[v] = idx;
    component.PB(v);
    for(int u : Gt[v]){
        if(!vis[u]) dfs2(u, idx + 1, component);
    }
}
vector<vector<int>> kosaraju(){ 
  vector<vector<int>> components;
  vis.assign(n,false);
  for(int i = 0; i < n; i++){
    if(!vis[i]) dfs1(i);
  }
  vis.assign(n,false);
  reverse(begin(order),end(order));
  int idx = 0;
  for(int v : order){
    if(!vis[v]){
      vector<int> component;
      dfs2(v, idx++, component); 
      // sort(begin(component),end(component));
      components.PB(component);
    }
  }
  return components; 
}

bool multiTest = false;

void solve(){
    int m;
    cin >> n >> m;
    G.resize(n);
    id.resize(n);
    vis.resize(n);
    Gt = G;
    colors = order = id;

    for (int z = 0; z < m ; z++){
        int i, u;
        cin >> i >> u;
        i--; u--;
        G[i].push_back(u);
        Gt[u].push_back(i);
    }

    auto c = kosaraju();
    for (int i = 0; i < n; i++){
      for (auto node : G[i]){
        int ci = 
        if (representants[i] == -1) representants[i] = i;
        if (representants[node] == -1) representants[node] = i;
      }
    }    
    cout << ans  << endl;
    
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