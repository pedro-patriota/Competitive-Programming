#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define double long long
#define pii pair<ll,ll>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define PB push_back
#define X first
#define Y second
#define br '\n'

const bool multitest = 0;



void solve(){
    ll n;
    double b; cin >> n >> b;
    if(n == 1){
        int l = 1 + (b-1)/2;
        int c = 1 + (int)(b-1) % 2;
        cout << l << " " << c << br;
        return;
    }
    ll l = 0, r = n/2 + 1;
    ll bestK = 0;
    while(l < r){
        ll k = l + (r-l)/2;
        double fk = 4*k * (n - k);
        if(fk < b){
            bestK = k;
            l = k + 1;
        }else{
            r = k - 1;
        }
    }

    
    pair<double, double> leftUp = {bestK + 1, bestK + 1 };
    pair<double, double> rightUp = {bestK + 1, n - bestK };
    double diff = (n - bestK) - (bestK + 1);
    pair<double, double> leftDown = {n - bestK, n - bestK - diff} ;
    pair<double, double> rightDown = {n - bestK, n - bestK};
    double x, y;

    cout << diff << endl;
    cout << (ll) leftUp.first << "," << (ll) leftUp.second << "   " << (ll) rightUp.first << "," << (ll) rightUp.second << endl;
    cout << leftDown.first << "," << leftDown.second << "   " << rightDown.first << "," << rightDown.second << endl;
    
    double presentBeans = 4*bestK * (n - bestK) + 1;
    cout <<  diff << " "   <<  presentBeans << endl;
    b -= presentBeans;

    if ( b <= diff){
        cout << (ll)  leftUp.first << " " << (ll) (leftUp.second + b) << br;
        return;
    }
    b -= diff;
    if (b <= diff - 1){
        cout << (ll) (rightUp.first + b) << " " << (ll) rightUp.second << br;
        return;
    }
    b -= diff;
    if (b <= diff){
        cout << (ll) rightDown.first << " " << (ll) (rightDown.second - b) << br;
        return;
    }
    b -= diff;
    cout << (ll) (leftDown.first - b) << " " << (ll) leftDown.second << br;
    return;




    // if(bestK == 0){
    //     if(b <= n){
    //         cout << 1 << " " << b << br;
    //         return;
    //     }
    //     b -= n;
    //     if(b <= n - 1){
    //         cout << n - b << " " << n << br;
    //         return;
    //     }
    //     b -= (n-1);
    //     if(b <= n - 1){
    //         cout << n << " " << n - b << br;
    //         return;
    //     }
    //     b -= (n-1);
    //     cout << n - b <<" " << 1 << br;
    //     return;
    // }
    // else{

    // }

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