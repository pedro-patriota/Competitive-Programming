#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second
#define PB push_back

bool multiTest = true;

string s;
bool isPos(int x){
    int cnt = 0;
    for (int i = 0; i < s.size() - x; i++){
        char left = s[i], right = s[i+x];
        if (left == right || (left == '?' || right == '?')){
            cnt++;
        }else{
            cnt = 0;
        }
        if (cnt == x) return true;
    }
    return false;
}

void solve(){
    cin >> s;    
    int l = 0, r = s.size()/2, m;

    for (int i = r; i > 0; i--){
        if (isPos(i)){
            l = i;
            break;
        }
    }
    cout << l*2 << endl;
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1;
    if (multiTest)
        cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}