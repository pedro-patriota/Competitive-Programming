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
vector<bool> vis;
vector<int> folhas;
void dfs(int node){
	vis[node] = true;
	bool isFolha = true;
	for(int filho : adj[node]){
		if(!vis[filho]){
			isFolha = false;
			dfs(filho);
		}
	}
	if(isFolha)	folhas.PB(node);
}

void solve(){
	int n, h; cin >> n >> h;
	adj = vector<vector<int>>(n);
	for(int i = 0; i < n - 1; i++){
		int x, y; cin >> x >> y;
		adj[x].PB(y);
		adj[y].PB(x);	
	}
	int g = adj[h].size();
	vector<vector<int>> grupos(g); // grupo[i] -> vetor de folhas
	int i = 0;
	int qtdFolhas = 0;
	for(int filho : adj[h]){
		folhas.clear();
		vis = vector<bool> (n+1,false);
		vis[h] = true;
		dfs(filho);
		grupos[i] = folhas;
		qtdFolhas += folhas.size();
		i++;
	}
	vector<int> pertence(n);
	// set<int> st;
	// for(int i = 0; i < g; i++){
	// 	// for(int el : grupo[i]){
	// 	// 	pertence[el] = i;
	// 	// }
	// 	// cout << "grupo" << br;
	// 	// for(int el : grup){
	// 	// 	cout << el << " ";
	// 	// }
	// 	// cout << br;
	// }
	vector<pii> edges;
	if(g == 1){
		// liga todo mundo ate o inicio
		return;
	}
	int proxGrupo = 1;
	vector<int> st(g,0);
	for(int i = 0; i < g; i++){
		int j = st[i];
		while(j < grupos[i].size()){ // pra cada elemento de grupo i procurar proximo grupo
			if(proxGrupo == g){
				if(j + 1 < grupos[i].size()){
					int a = grupos[i][j];
					int b = grupos[i][j+1];
					edges.PB({a,b});
					j += 2;
					continue;
				}
				else{
					int a = grupos[i][j];
					edges.PB({a,0});
					j++;
					continue;
				}
			}
			else{
				int a = grupos[i][j];
				int b = grupos[proxGrupo][st[proxGrupo]];
				if(a == b){
					edges.PB({a,0});
					j++;
					continue;
				}
				edges.PB({a,b});
				st[proxGrupo]++;
				if(st[proxGrupo] == grupos[proxGrupo].size()) proxGrupo++;
			}
			j++;
		}	

	}
	cout << edges.size() << br;
	for(auto [a,b] : edges){
		cout << a << " " << b << br;
	}

}

int main(){
	io;
	// freopen("digits.in", "r", stdin);
	// freopen("digits.out", "w", stdout);
	int t = 1;
	if(multitest) cin >> t;
	while(t--){
		solve();
	}
}