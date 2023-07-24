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

vector<ll> getDivisors(ll n){
	vector<ll> ans;
	for(ll i = 1; i*i <= n; i++){
		if(n % i == 0){
			ans.PB(i);
			if(i != n/i) ans.PB(n/i);
		}
	}
	sort(begin(ans),end(ans));
	return ans;
}

void solve(){
	ll n; cin >> n;
	ll best = LLONG_MAX;
	vector<ll> divisors = getDivisors(n);
	ll sz = divisors.size();
	for(ll i = 0; i < sz; i++){
		ll x = divisors[i];
		for(ll j = 0; j < sz; j++){
			ll y = divisors[j];
			if(x*y > n) break;
			if(n % (x*y) != 0) continue;
			ll z = n / (x*y);
            //out << x << " " << y << " " << z << endl;
			ll somaArea =  2*(x*y + x*z + y*z);
			best = min(best,somaArea);
		}
	}
	cout << best << br;
}

int main(){
	io;
	// freopen("digits.in", "r", stdin);
	// freopen("digits.out", "w", stdout);
	//cout << setprecision(15) << fixed;
	int t = 1;
	if(multitest) cin >> t;
	while(t--){
		solve();
	}
}