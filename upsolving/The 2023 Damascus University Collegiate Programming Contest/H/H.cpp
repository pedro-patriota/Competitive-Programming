#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<ll, ll>
#define X first
#define Y second

bool multiTest = false;

ll calc (vector<ll>& prefix, ll sum, ll x){
    ll n = prefix.size(), l,  r, m;

    l = 0;
    r = n - 1;
    if (x >= prefix[r] + sum*n) return n;
    while (l < r){
        m = (l + r + 1)/2;
        if (x >= prefix[m] + sum*(m + 1)){
            l = m;
        }else{
            r = m - 1;
        }
    }
    return l + 1;
    
}

void solve(){

    ll n;
    cin >> n;
 
    vector<vector<ll>> colors (2e5 + 7);
    vector<ll> arrA (n);
    vector<ll> arrC (n);

    for (ll i = 0 ; i < n ; i ++){
        cin >> arrA[i];
    }
    for (ll i = 0 ; i < n ; i ++){
        cin >> arrC[i];
    }
    for (ll i  = 0 ; i < n ; i ++){
        ll a1 = arrA[i];
        ll c1 = arrC[i];
        if (colors[c1].size() == 0){
            colors[c1].push_back(a1);
            continue;
        }

        ll pos = colors[c1].size() - 1;
        colors[c1].push_back(a1 + colors[c1][pos]);
    }
    ll op, type, x,  c, sum = 0;
    cin >> op;

    vector<ll> diff (2e5 +  17, 0);

    for (ll i = 0; i < op; i++){
        cin >> type >> c >> x;
        if (type == 1){
            sum += x;
            diff[c] += x;
        }else{
            int ans  = calc(colors[c], (sum - diff[c]), x);
            cout << ans << endl;
        }
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