#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    ll n, x, largestSum = 0, counter = 0;
    cin >> n >> x;
    vector<ll> arr(n);
    for (ll i = 0; i < n ; i ++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    if (arr.size() == 1) {cout << 1; return 0;}
    counter = 1;
    largestSum = arr[0];

    for (ll i = 1; i < n; i++){
        if (i == 1){
            largestSum += arr[i];
        }else{
            largestSum -= arr[i-2];
            largestSum += arr[i];
        }

        if (largestSum > x){
            break;
        }else{
            counter++;
        }
    }
    
    cout << counter;
        
    return 0;
    
}