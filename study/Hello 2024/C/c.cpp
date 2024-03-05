#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second
#define PB push_back

bool multiTest = true;

int n, ans =0;
void solve(){
    cin >> n;
    stack<int> a, b;
    ans = 0;
    for (int i = 0; i < n; i++){
        int val; cin >> val;

        if (a.empty()){
            a.push(val);
        }
        else{
            if (val <= a.top()){
                a.push(val);
            }else{
                if (b.empty()) {
                    b.push(val);
                }else{
                    if (val <= b.top()){
                        b.push(val);
                    }else{
                        if (a.top() <= b.top()){
                            a.push(val);
                        } else b.push(val);
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
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