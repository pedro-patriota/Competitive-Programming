#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second

bool multiTest = true;

vector<ll> comb (42);
void preCalc(int v){
    for (int i = v; i >= 1; i--){
        comb[v] = max(comb[v], (ll) pow(i, v/i));
    } 
}

int p;
bool isPos = false;
vector<int> st;
void backTracking (int i, int n, ll temp){
    if (n >= 41) return;
    if (temp == p && i == 0) isPos = true;
    if (isPos) return;
    if (p/temp > comb[i]) return;
    if (temp > p ) return;
    if (i == 0) return;
    for (int v = i; v > 0; v--){
        backTracking(i -v, n + 1, temp * v);
        if (isPos){
            if (v != 0){
                 st.push_back(v);
            }
           
            return;
        }

    }

}
int cs = 1;
void solve(){
    cin >> p;
    st = {};
    isPos = false;
    backTracking(41, 1, 1);
    cout << "Case #" << cs << ": ";
    if (isPos){
        cout << st.size();
        for (auto v : st){
            cout << " " << v;
        }
    }else{
        cout << -1;
    }
    cout << endl;

    cs++;

}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1;
    if (multiTest) cin >> t;
    for (int i = 41; i > 0; i --){
        preCalc(i);
    }
    while(t--){
        solve();
    }
    return 0;
    
}