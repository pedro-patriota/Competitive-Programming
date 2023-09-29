#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    ll k1, k2;
    cin >> k1 >> k2;
    bool ispos = false;

    for (ll k = 0; k <  3*1e6 + 17; k++){
        ll newK1 = round((double) 1/3 * k);
        ll newK2 = round((double) 1/2 * k);
        if (newK1 == k1 && newK2 == k2){
            cout << k << " ";
            ispos = true;
        }
    }
    if (not ispos) cout << 0;
    
        
    return 0;
    
}