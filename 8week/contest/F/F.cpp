#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, t;

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> t;
    ll time;
    vector<ll> preff(n);
    vector<ll>  books(n);
    cin >> time;
    books[0] = preff[0] = time;
    for (ll i = 1; i < n; i++){
        cin >> time;
        books[i] = time;
        preff[i] = preff[i-1] + time;

    }
    ll max = 0;
    auto it = preff.begin();
    for (ll i = 0; i < n; i++){
        ll limit = *it + (t - books[i]);
        auto up = upper_bound(preff.begin(), preff.end(), limit);
        if (up - it > max){
            max = up - it;
        }
        it++;
    }
    cout << max;
    
    
}