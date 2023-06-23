#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    double n, x;
    cin >> n >> x;
    vector<double> arr(n);
    ll avr = 0;
    bool total_silence = true;
    for (ll i = 0; i < n; i++){
        cin >> arr[i];
        if (abs(arr[i]) > 0){
            total_silence = false;
        }
        avr += (arr[i]*arr[i]);
    }
    if (x == 0 || total_silence){
        for (ll i = 0; i < n; i++){
            cout << 0  << " ";
        }
        return 0;
    }
    double coef;
    coef = sqrt((double) n*x/avr);
    for (ll i = 0; i < n; i++){
        cout << setprecision(12) <<arr[i]*coef << " ";
    }
    
        
    return 0;
    
}