#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m;
const ll MOD = 1e8 + 1;

ll fastexpo(ll a, ll b){
    ll ans = 1;
    while (b){
        if (b & 1) ans = (ans * a);
        if (ans > MOD){
            return MOD;
        }
        a = (a*a);
        b >>= 1; 
    }
    return ans;
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> m;

    ll ans = fastexpo(2, n);
    cout << m%ans;
    
}