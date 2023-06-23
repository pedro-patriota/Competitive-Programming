#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int MAX_FAC_N = 19;

ll factorial[MAX_FAC_N];
vector<ll> combArr;

void comb(int N, int K)
{
    string bitmask(K, 1); // K leading 1's
    bitmask.resize(N, 0); // N-K trailing 0's
 
    // print integers and permute bitmask
    do {
        for (int i = 0; i < N; ++i) // [0..N-1] integers
        {
            if (bitmask[i]) cout << " " << i;
        }
    } while (prev_permutation(bitmask.begin(), bitmask.end()));
}

ll combination(ll n1, ll n2){
    return factorial[n1]/(factorial[n2]*factorial[n1 - n2]);
}

ll preCalc(set<ll> arr, ll n1, ll fixedDigit){
    // repeats with itself
    ll lastDigit, ans = 0;
    lastDigit = n1/(10*(fixedDigit-1));
    ll num_digits = ceil(log10l(n1));
    
    combArr[0] = lastDigit;
    for (int i = 1; i < fixedDigit; i++){
        combArr[i] = 10;
    }

    for (int i = fixedDigit; i >=  1; i--){

    }



}

ll solve(ll n1){
    if (n1 <= 10){
        return n1;
    }
}


int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    
    factorial[1] = 1;
    for (int  i = 2; i < 19; i++){
        factorial[i] = factorial[i-1]*i;
    }

    ll t, n1, n2;
    cin >>t;
    
    for (ll i = 0; i < t; i++){
        cin >> n1 >> n2;
    }
    
        
    return 0;
    
}