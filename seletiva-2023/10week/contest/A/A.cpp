#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll n;

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<ll> arr1(n); 
    vector<ll> arr2(n); 
    for (ll i = 0; i < n; i++){
        cin >> arr1[i];
    }   
    for (ll i = 0; i < n; i++){
        cin >> arr2[i];
    }
    ll ans = 0;
    if (n == 1){
        cout << max(arr1[0], arr2[0]) << endl;
    }
    arr1[1] = arr1[1] + arr2[0];
    arr2[1] = arr1[0] + arr2[1];
    if (n == 2){
        cout << max(arr1[1], arr2[1] ) << endl;
    }
    for (ll i = 2; i < n; i++){
        arr2[i - 1] = max(arr2[i-1], arr2[i-2]);
        arr1[i - 1] = max(arr1[i-1], arr1[i-2]);
        arr1[i] = arr1[i] + arr2[i-1];
        arr2[i] = arr2[i] + arr1[i-1];
    }
    cout << max(arr1[n-1], arr2[n-1]) << endl;


}