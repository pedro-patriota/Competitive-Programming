#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second
#define PB push_back

bool multiTest = true;

ll m, f, a, b, t, next_t;
void solve(){
    cin >> m >> f >> a >> b;
    t = 0;
    for (int i = 0; i < m; i++){
        cin >> next_t;
        if (f - b > f - (next_t - t)*a){
            f -= b;
        }else{
            f -= (next_t - t)*a;
        }
        t = next_t;
    }
    if (f > 0) cout << "YES" << endl;
    else cout << "NO" << endl;
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