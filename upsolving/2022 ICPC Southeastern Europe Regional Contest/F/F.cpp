#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct DSU {
	int getSize(int x) { return -par[getPar(x)]; }
	int getPar(int x) {
		while(par[x] >= 0) {
			x = par[x];
		}
		return x;
	}
    void makeUnion(int a, int b) {
		a = getPar(a), b = getPar(b);
		if(a == b) return ;
		if(a > b) std::swap(a, b);
		op.emplace_back(a, par[a]);
		op.emplace_back(b, par[b]);
		par[a] += par[b];
		par[b] = a;
       
	}
 
	void init(int n) {
		par.resize(n);
		for(int i = 0; i < n; i++) {
			par[i] = -1;
		}
		op.clear();
	}
 
	std::vector<int> par;
	std::vector<std::pair<int, int>> op;
};


int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    ll fights[n][n];
    vector<pair<ll, ll>> combos;

    DSU dsu;
    dsu.init(n);

    for (ll i = 0; i < n ; i++){
        for (ll j = 0; j < n; j++){
            ll famous1, famous2;
            cin >> fights[i][j];
        }
    }
    map<pair<ll, ll>, ll> fightsArr;
    for (ll i = 0; i < n ; i++){
        for (ll j = i; j < n; j++){
            fightsArr[{i, j}] = fights[i][j];
            //cout << i+1  << " " << j+1 << " -> " << fights[i][j] <<endl;
        }
    }
    multimap<ll, pair<ll, ll>, greater<ll>> bestFights;
    for (auto [ pp, popularity] : fightsArr){
        bestFights.insert({popularity, pp});
    }
    vector<pair<ll, ll>> ans;
    ll sum = 0;
    for (auto [popularity, pp] : bestFights){
        if (ans.size() == n -1) break;
        auto [i, j] = pp;
        int a = dsu.getPar((int) i),  b = dsu.getPar((int) j );
        
        if (a != b){
            ans.push_back({(ll) a, (ll) b});
            sum += popularity;
            dsu.makeUnion(a, b);
        }
    }
    cout << sum << endl;
    for (auto [a, b] : ans){
        cout << a + 1 << " " << b + 1<< endl;
    }

        
    return 0;
    
}   