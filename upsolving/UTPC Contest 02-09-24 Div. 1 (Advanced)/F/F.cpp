#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second
#define PB push_back

bool multiTest = false;

const ll M = 1e9 + 7;

ll fastExpo(ll a, ll b){
    ll ans = 1;
    while (b){
        if (b & 1) {
            ans = (ans *  a)%M;}
        a = (a *a)%M;
        b >>= 1;
    }
    return ans%M;
}

void solve(){
    int n, k; 
    cin >> n >> k;
    cout << fastExpo(2, min(n-k, k));
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