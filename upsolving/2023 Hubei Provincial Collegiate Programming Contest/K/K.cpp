#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll MOD  = 998244353;
const ll expn = 998244351;

ll fastModExp(ll x, ll y, ll m){
    ll ans = 1;
    x = x % m;      // Update 'x' if it is more than or equal to 'm'
    while(y){ // We walk through the bits of power "y"
        if(y & 1) ans = (ans*x) % m; // If the least significant bit is set, we multiply the answer by "x"
        y = y >> 1; // We walk to the next bit
        x = (x*x) % m;
    }
    return ans;
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, total;
    cin >> n >> m;
    total  = fastModExp(m-1, n, MOD);
    total = fastModExp(total, expn, MOD);
    cout << 1 << " ";
    for (int i = 2; i < m; i++){
        ll pos = m - i;
        pos = fastModExp(pos, n, MOD);
        cout << pos*total%MOD << " ";
    }
    cout << 0;
        
    return 0;
    
}