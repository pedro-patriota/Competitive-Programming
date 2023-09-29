#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pii pair<ll,ll>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define PB push_back
#define X first
#define Y second
#define br '\n'

const bool multitest = 0;

vector<vector<int>> adj;
vector<int> path;
vector<bool> vis;
int n,x;

bool dfs(int node){
	vis[node] = true;
	if(node == x){
		path.PB(node);
		return true;
	}
	for(int nb : adj[node]){
		if(!vis[nb]){
			if(dfs(nb)){
				path.PB(node);
				return true;
			}
		}
	}
	return false;
}

ll countFilhos(int node){
	vis[node] = true;
	ll ans = 0;
	for(int nb : adj[node]){
		if(!vis[nb]){
			ans = 1 + countFilhos(nb);
		}	
	}
    queue<int> p;
    p.pop()
	return ans;
}


void solve(){
	cin >> n >> x;
	x--;
	adj.resize(n);
	for(int i = 0; i < n - 1; i++){
		int a,b; cin >> a >> b;
		a--;b--;
		adj[a].PB(b);
		adj[b].PB(a);
	}
	vis.assign(n,false);
	dfs(0);
	vis.assign(n,false);
	ll p = path.size()-1; //
	for(int i = 0; i <= p; i++){
		vis[path[i]] = true;
	}
	ll k = countFilhos(path[0]) + countFilhos(path[1]);
	// cout << k << " " << p << br;
	ll ans = 2*(n-1-k-p) + p;
	cout << ans << br;

}	

int main(){
  io;
  // freopen("digits.in", "r", stdin);
  // freopen("digits.out", "w", stdout);
  // cout << setprecision(10) << fixed;
  int t = 1;
  if(multitest) cin >> t;
  while(t--){
    solve();
  }
}