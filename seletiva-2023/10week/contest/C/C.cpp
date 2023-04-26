#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    ll n, w;
    cin >> n >> w;
    vector<ll> arr(n);
    vector<ll> prefix(n+1);

    for (ll i = 0; i < n; i++){
        cin >> arr[i];
    }
    prefix[1] = arr[0];
    for (ll i = 1; i < n; i++){
        prefix[i+1] = prefix[i] + arr[i];
    }
    ll ans = 0;
    sort(prefix.begin(), prefix.end());
    ll min_val = prefix[0];
    ll max_val = prefix[n];
    ll relative_min =  abs(min_val); 
    ll relative_max =  abs(max_val); 
    if (relative_max>  w){
        cout << 0 << endl;
        return 0;
    }
    if (relative_min > w){
        cout << 0 << endl;
        return 0;
    }
    ans = (w - max(relative_max, (ll) 0)) - relative_min + 1;
    cout << ans << endl;



        
    
    
}