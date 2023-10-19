#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second

bool multiTest = true;

vector<int> kmp(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

bool check(string pat, string s){
    string aux = pat;
    aux += '#';
    aux += s;
    vector<int> vec = kmp(aux);
    for (auto i : vec){
        if (i == pat.size()){
            return true;
        }
    }
    return false;
}

void solve(){
    int n, m;
    string nS, mS;
    cin >> n >> m;
    cin >> nS >> mS;
    int op = 0;
    bool pos = true;
    while (not check(mS, nS)){
        nS += nS;
        op++;
        if (op > 10){
            pos = false;
            break;
        }
    }
    if (not pos){
        cout << -1 << endl;
    }else{
        cout << op << endl;
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