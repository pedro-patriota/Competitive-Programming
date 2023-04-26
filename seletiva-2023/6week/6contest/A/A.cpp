#include <bits/stdc++.h>
using namespace std;
#define ll long long
string p1, p2, ans;

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> p1;
    cin >> p2;
    for (ll i  = p1.size() -1; i >= 0 ; i--){
        if (p1[i] == p2[i]){
            ans += '0';
        }else{
            ans += '1';
        }
    }
    cout << ans;
    
}