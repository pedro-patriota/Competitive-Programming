#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second
#define PB push_back

bool multiTest = true;
int x, y, based_x, based_y;
void solve(){
    cin >> based_x >> based_y; 
    for (int i = 0; i < 3; i++){
        cin >> x >> y;
        if (x == based_x){
            cout << abs(based_y - y)*abs(based_y - y) << endl;
            based_x == -1;
        }
    }
    
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