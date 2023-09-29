#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define ii pair<ll, ll>
#define X first
#define Y second

vector<ii> getFactors(ll n){
    vector<ii> primes;
    primes.push_back({1, 1});
    for(int p = 2; p*p <= n; p++){
        if(n%p==0){
            int exp = 0;
            while(n%p == 0){
                exp++;
                n/=p;
            }
            primes.push_back({p, exp});
        }
    }
    if(n > 1) primes.push_back({n, 1});
 
    return primes;
}


int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    ll n;

    cin >> n;
    vector<ii> factors = getFactors(n);
    ll p = 1;
    for ( auto [fact, _] : factors){
        p *= fact;

    }
    ll s = p;
    while (true){
        ll aux = p + n;
        if (aux*aux % n == 0){
            cout << (aux * aux)/n - n << endl;
            break;
        }
        p += s;
    }
  
    ll cnt = n + 1; 
   /*  while (true){
        if ((ll) cnt*cnt % n == 0) {
            cout << (cnt*cnt)/n - n << endl;
            break;
        }
        cnt += 1;
    } */
        
    return 0;
    
}