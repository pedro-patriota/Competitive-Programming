#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
//#define endl '\n'
#define ii pair<ll, ll>
#define X first
#define Y second

bool multiTest = true;
ll n;
vector<ld> arr;
ld walk = 0;

bool posDist(ld dist){
    ll qntGroup = 1;
    ll beg = 0;
    ld med =  (arr[0] + arr[1])/2;
    vector<ld> walks;

    for (ll i = 2; i < n; i++){
        ld newMed = (arr[beg] + arr[i])/2;
        if (med != -1 && newMed - med > dist){
            if (i - beg < 2){
                return false;
            }
            walks.push_back(med);
            qntGroup++;
            beg = i;
            med = -1;
        }else{
            med = newMed;
        }
    }
    if (n - beg < 2){
        return false;
    }
    walks.push_back(med);
    ld prev = -1, temp = 0;
    for (auto v : walks){
        if (prev != (ld) -1){
            temp += abs(v - prev);
        }
        prev = v;
    }
    walk = max(temp, walk);


    return true;
}
ll cs = 1;
void solve(){
    cin >> n;
    arr.assign(n, 0);
    for (ll i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    ld d = 0, t = 0;
    for (ll i = 0; i < n/2 ; i ++){
        t += arr[i];
    }
    for (ll i = n/2; i < n ; i ++){
        d += arr[i];
    }
    walk = (d/(n - n/2) - t/(n/2));


    ld l = 0, r = 1e9 + 17, m;
    while (r - l > 1e-7){
        m = (l + r)/2;
        if (posDist(m)){
            r = m;
        }else{
            l = m;
        }
    }
    cout << "Case #" << cs << ": " << walk << endl;
    cs++;


}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    freopen("inputB1.txt", "r", stdin);
    cout  << setprecision(14) << fixed;
    ll t = 1;
    if (multiTest) cin >> t;
    while(t--){
        solve();
    }
    return 0;
    
}