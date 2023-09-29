#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    ll a, mina = 1e11, maxa = -1e11, best;
    double diff = 1e11;
    vector<ll> arr(n);

    for (int i = 0 ; i < n ; i ++){
        cin >> a;
        arr[i] = a;
        mina = min(mina, a);
        maxa = max (maxa, a);

    }
    sort(arr.begin(), arr.end());
    double mean = (double) (mina + maxa)/2;

    for (int i  = 0; i < n; i++){
        double localDiff = abs((double) arr[i] - mean);

        if (localDiff < diff){
            best = arr[i];
            diff = (double) localDiff;
        }

    }   
    cout << best << endl;
    
        
    return 0;
    
}