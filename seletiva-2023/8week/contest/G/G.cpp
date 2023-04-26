#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<ll> left_gdc(n);
    vector<ll> right_gdc(n);

    left_gdc[0] = arr[0];
    for (ll i = 1; i < n; i++){
        left_gdc[i] = __gcd(left_gdc[i -1], arr[i]);
    }
    right_gdc[n-1] = arr[n-1];
    for (ll i = n-2; i >= 0; i--){
        right_gdc[i] = __gcd(right_gdc[i+1], arr[i]);
    }
    ll res = 1;
    for (ll i = 0; i < n; i++){

        ll left_to_i = i == 0 ? 0 : left_gdc[i - 1];
        ll right_to_i = i == n-1 ? 0 : right_gdc[i + 1];

        res = max(res, __gcd(left_to_i, right_to_i));
    }
    cout << res;

    
    
}