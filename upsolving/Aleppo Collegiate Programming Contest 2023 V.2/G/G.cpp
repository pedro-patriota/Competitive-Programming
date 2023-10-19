#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<ll, ll>
#define X first
#define Y second
const ll MOD = 1e9 + 7;


ll fexp(ll a, ll b) {
  ll ans = 1;
  while(b) {
    if(b & 1) ans = ans * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return ans;
}

ll test(vector<ll>& arr) {
    ll ans = 0;
    for (int d = 0; d < (1 << arr.size()); d++) {
        vector<ll> sub;
        for (int i = 0; i < arr.size(); i++) {
            bool isOne = 1 & (d >> i);
            if (isOne) {
                sub.push_back(arr[i]);
            }
        }
        int beg = 0, prev = -1;
        for (auto v : sub) {
            if (prev != -1) {
                if (v == prev) {
                    beg--;
                }
            }
            if (v != beg) {
                break;
            }
            beg++;
            prev = v;
        }
        ans = (ans % MOD + beg % MOD) % MOD;  // Perform modular operation here
    }
    return ans % MOD;  // Perform modular operation here
}


int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    ll t; cin >> t;
    while (t--)
    {
        ll n; cin >> n;
        vector<ll> arr (n);
        for (ll i = 0 ; i < n ; i ++){
            cin >> arr[i];
        }    
        sort(arr.begin(), arr.end());
        ll beg = 0, cnt = 1, ans = 0, f = 0;
        for (ll i = 0 ; i < n; i++){
            if (i > 0){
                if (arr[i - 1] == arr[i]){
                    beg--;
                    f++; 
                }else {
                    cnt = (cnt % MOD *(fexp(2, f + 1)-1)%MOD )%MOD;
                    f = 0;
                }
            }
            if (arr[i] != beg){
                break;
            }
            ll up = (upper_bound(arr.begin(), arr.end(), beg + 1) - arr.begin());
            ll afterPos = n - up;
            // Apply modular operation to intermediate result
            ll aux = (cnt * fexp(2, f)) % MOD * fexp(2, afterPos) % MOD;
            // Perform modular operation to final result
            ans = (ans + (beg+1) * aux) % MOD;
            beg++;
        }
        cout << test(arr) << endl;
        cout << ans << endl;
    }
    
    
    return 0;
}
