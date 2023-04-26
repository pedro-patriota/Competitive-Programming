#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll B, P, M;
const ll MOD = 2147483647;
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

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    int trash;
    while (cin >> B){
        cin >> P;
        cin >> M;

        ll aux = B%M;
        
        ll ans = fastExpo(aux, P);
        cout << ans << "\n"; 
    }
    
    
}