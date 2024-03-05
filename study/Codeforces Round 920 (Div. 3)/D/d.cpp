#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second
#define PB push_back

bool multiTest = true;

ll n, m, xA, xB, yA, yB, diff;

void solve(){
    cin >> n >> m;
    vector<int> a (n);
    vector<int> b (m);
    diff = 0;

    for (int i = 0; i < n; i ++){
        cin >> a[i];
    }
    for (int i = 0; i < m; i ++){
        cin >> b[i];
    }
    sort (a.begin(), a.end());
    sort (b.begin(), b.end());

    xA = xB = 0;
    yA = n - 1;
    yB = m - 1;

    for (int i =0; i < n; i++){
        if (abs(a[xA] - b[yB]) > abs(a[yA] - b[xB])){
            diff += abs(a[xA] - b[yB]);
            xA++;
            yB--;
        }else{
            diff += abs(a[yA] - b[xB]);
            yA--;
            xB++;
        }
    }
    cout << diff << endl;

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