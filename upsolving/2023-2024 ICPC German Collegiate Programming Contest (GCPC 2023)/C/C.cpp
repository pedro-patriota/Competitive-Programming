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

template<class T>
T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }
 
template<class T>
struct Frac {
	T p, q;
	Frac() {
		p = 0, q = 1;
	}
	Frac(T x) {
		p = x;
		q = 1;
	}
	Frac(T a, T b) {
		if(b == 0) {
			a = 0;
			b = 1;
		}
		p = a;
		q = b;
		fix();
	}
	Frac<T> operator + (Frac<T> o) const { return Frac(p * o.q + o.p * q, q * o.q); }
	Frac<T> operator - (Frac<T> o) const {return Frac(p * o.q - o.p * q, q * o.q); }
	Frac<T> operator * (Frac<T> o) const { return Frac(p * o.p, q * o.q); }
	Frac<T> operator / (Frac<T> o) const { return Frac(p * o.q, q * o.p); }
 
	void fix() {
		if(q < 0) {
			q = -q;
			p = -p;
		}
		auto g = gcd(std::max(p, -p), q);
		p /= g;
		q /= g;
	}
 
	bool operator < (Frac<T> o) const { return ((*this) - o).p < 0; }
	bool operator > (Frac<T> o) const { return ((*this) - o).p > 0; }
 
	friend std::ostream& operator << (std::ostream &os, const Frac<T> &f) {
		return os << f.p << '/' << f.q;
	}
	friend std::istream& operator >> (std::istream &is, Frac<T> &f) {
		char trash;
		return is >> f.p >> trash >> f.q;
	}
};
vector<bool> isWorm;
vector<int> worms;
vector<vector<int>> adj;
Frac<ll> currD;
vector<int> dist;
Frac<ll> soma;
int n, m, k;

void bfsDist(int node){
	vector<bool> vis(n+1,false);
	queue<int> q;
	q.push(node);
	int d = 0;
	vis[node] = true;
	while(!q.empty()){
		int lvlSz = q.size();
		while(lvlSz--){
			int curr = q.front();
			q.pop();
			dist[curr] = d;
			for(int nb : adj[curr]){
				if(!vis[nb]){
					vis[nb] = true;
					q.push(nb);
				}
			}
		}
		d++;
	}
}

void bfs(int node){
	vector<bool> vis(n+1,false);
	queue<int> q;
	q.push(node);
	vis[node] = true;
	Frac<ll> um(1,1);
	Frac<ll> d;
	while(!q.empty()){
		int lvlSz = q.size();
		while(lvlSz--){
			int curr = q.front();
			q.pop();
            //if (curr == n -1) return;
            //cout << "VISITEI " << curr << endl;
			if(isWorm[curr]){
				Frac<ll> pasp(dist[curr],k-1);
				currD = min(currD, d + (soma - pasp));
			}else{
				Frac<ll> luan(dist[0]);
				currD = min(currD, luan);
			}
            //cout << currD << endl;
			for(int nb : adj[curr]){
				if(!vis[nb]){
					vis[nb] = true;
					q.push(nb);
				}
			}
		}
		d = d + um;
	}

}


void solve(){
	cin >> n >> m >> k;
	isWorm = vector<bool>(n);
	adj = vector<vector<int>>(n);
	dist = vector<int>(n);
	currD = Frac<ll>(1e9);
	for(int i = 0; i < k; i++){
		int x; cin >> x;
		x--;
		isWorm[x] = 1;
		worms.PB(x);
	}
	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		x--;y--;
		adj[x].PB(y);
		adj[y].PB(x);
	}
	bfsDist(n-1);
	// for(int i = 0; i < n; i++){
	// 	cout << dist[i] << " - ";
	// }
	// cout << br;
	for(int worm : worms){
		Frac<ll> pasp(dist[worm],k-1);
		soma = soma + pasp;
	}
	//cout << soma << br;
	bfs(0);
	cout << currD << br;
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