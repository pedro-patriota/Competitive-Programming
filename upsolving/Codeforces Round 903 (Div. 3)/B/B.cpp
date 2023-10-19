#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second

bool multiTest = true;

void solve(){
    int a, b, c;
    multiset<int, greater<int>> q;
    cin >> a >> b >> c;
    q.insert(a);
    q.insert(b);
    q.insert(c);
    int op = 0;
    int top = *(q.begin());
    int end = *(--q.end());
    while (top != end){
        q.erase(q.begin());
        q.insert(end);
        q.insert(top - end);

        top = *(q.begin());
        end = *(--q.end());
        op ++;
        if (op > 3){
            break;
        }
    }
    if (op > 3){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
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