#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll n, cx, cy, r, c1, c2;

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> cx >> cy>> r;
    ll count = 0;
    for (ll i = 0; i < n; i++){
        cin >> c1 >> c2;
        if (abs(c1 - cx) > r){
            continue;
        }
        if (abs(c2 - cy) > r){
            continue;
        }
        double dist_r = sqrt(((cx-c1)*(cx-c1)) + ((cy-c2)*(cy-c2)));
        if (dist_r <= r){
            count++;
        }
    }
    cout << count;
    
}