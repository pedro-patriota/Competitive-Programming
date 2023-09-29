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

    int n, k;
    cin >> n;
    vector<ll> arr (n);
    vector<ll> prefix (n + 1);
    prefix[0] = 0;

    for (int i  = 0 ; i < n ; i++) { cin >> arr[i];  }
    sort(arr.begin(), arr.end());
    for (int i = 0 ; i < n ; i ++ ){
     prefix[i + 1] = prefix[i] + arr[i];

    }
    cin >> k;



    for (int i  = 0; i < k ; i ++ ){
        ll l;
        cin >> l;
        int pos = upper_bound(arr.begin(), arr.end(), l) - arr.begin();
        if (pos == n){
            cout << 0 << endl;
            continue;
        }
        pos--;
        /* if (pos == 0){
            
        } */
        
        int diff = (n-1 - (pos))*l;
        ll ans = prefix[n] -  prefix[pos+1] - diff;
            cout << pos << " "<< ans << endl;


    }

    
        
    return 0;
    
}   