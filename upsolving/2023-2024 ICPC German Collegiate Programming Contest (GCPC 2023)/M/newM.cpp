
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pii pair<ll,ll>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define PB push_back
#define X first
#define Y second
#define br '\n'

const bool multitest = 0;

int n;
int check(int k){
    if(k == 1) return false;
    if(k == 2) return false;
    if(3+k == n) return false;
    if(k-3 == n) return false;
    if(1+k == n) return false;
    if(k-1 == n) return false;
    if(2+k == n) return false;
    if(k-2 == n) return false;
    if(3*k == n) return false;
    if(2*k == n) return false;
    if(k == n) return false;
    if(2*k+1 == n) return false;
    if(2*k-1 == n) return false;
    if(k % 2 == 0 && k/2 == n) return false;
    if(k % 2 == 0 && k/2 + 1 == n) return false;
    if(k % 2 == 1 && (k+1)/2 == n) return false;
    if(k % 2 == 1 && (k-1)/2 == n) return false;
    if(k % 2 == 0 && k/2 - 1 == n) return false;
    if(k % 3 == 0 && k/3 == n) return false;
    return true;
}

void solve(){
    int a,b,c;
    cin >> n;
    if (n <= 10){
        cout << "47 75 100" << endl;
    }else{
        cout << "1 2 3" << endl;
    }
    /* a = 1; b = 2;
    for(int i = 3; i <= 100; i++){
        if(check(i)){
            c = i;
            break;
        }
    }
    cout << a << " " << b << " " << c << br; */
}

int main(){
    io;
    // freopen("digits.in", "r", stdin);
    // freopen("digits.out", "w", stdout);
    // cout << setprecision(10) << fixed;
    int t = 1;
    if(multitest) cin >> t;
    while(t--){
        solve();
    }
}
