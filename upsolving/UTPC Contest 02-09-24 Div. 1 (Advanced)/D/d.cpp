#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<ll, ll>
#define X first
#define Y second
#define PB push_back

bool multiTest = false;
vector<ll> arr;
ll l = 1, r = 1e11 + 7, m, n, k;

bool check(ll v){
    ll slice = v;
    ll pizzas = k;
    for (ll i = 0; i < n; i++){
        if (arr[i] > v) return false;

        if (arr[i] > slice){
            slice = v - arr[i];
            pizzas--;
        }else{
            slice -= arr[i];
        }
        if (pizzas == 0) return false;
    }
    return true;
}

void solve(){
    cin >> n >> k;
    arr = vector<ll>(n);
    for (ll i  = 0; i < n ; i ++){
        cin >> arr[i];
    }
    while (l < r){
        m = (l + r)/2;

        if (check(m)){
            r = m;
        }else{
            l = m + 1;
        }
    }
    cout << l;
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