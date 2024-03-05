#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second
#define PB push_back

bool multiTest = false;
ll mod = 1e9 +7;
int n, r, g, b, cr, cg, cb;

void solve(){
    cin >> n >> cr >> cg >> cb;
    ll ways = 0;
    bool br, bg, bb;
    for (int lv = 1; lv <= n; lv++){
        r = cr; g = cg; b = cb;
        for (int bitmask = 1; bitmask < 8; bitmask++){
            int i = lv;
            br = (bitmask >> 0) & 1;
            bg = (bitmask >> 1) & 1;
            bb = (bitmask >> 2) & 1;
            int total = br + bg + bb;
            int per_color = i/total;

            if (i%total != 0) continue;
            if (br && r < per_color) continue;
            if (bg && g < per_color) continue;
            if (bb && b < per_color) continue;
            
            if (br) r-= per_color;
            if (bg) g-= per_color;
            if (bb) b-= per_color;

            ll up = i, down = per_color;
            for (int j = 1; j < per_color; j++){
                i -= j;
                up = (up%mod * (i)%mod)%mod;
                down = (down%mod * (per_color-j)%mod)%mod;
            }
            for (int j = 1; j < per_color; j++){
                i -= j;
                up = (up%mod * (i)%mod)%mod;
                down = (down%mod * (per_color-j)%mod)%mod;
            }
            for (int j = 1; j < per_color; j++){
                i -= j;
                up = (up%mod * (i)%mod)%mod;
                down = (down%mod * (per_color-j)%mod)%mod;
            }
            ways = (up/down + ways)%mod;
        }
    }
    cout << ways << endl;
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