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

    int n, numZero = 0, numOne = 0;
    cin >> n;
    vector<int> bits (n + 7);
    for (int  i = 1; i <= n ; i ++) cin >> bits[i];
    vector<ll> arr (n + 7, 0);
    vector<ll> arrForBits(n + 7, 0);
    for (int i = n; i > 0; i--){
        if (bits[i] == 0){
            numZero++;
            arr[i] += arr[i + 1];
        }
        else{
            numOne++;
            arr[i] +=  1 + numZero;
            arrForBits[numOne] = arr[i];
            numZero = 0;
            if (numOne < 2) continue;
            arr[i] += arrForBits[numOne - 2];
            arrForBits[numOne] = arr[i];    
        }
    }
    ll sum = 0;
    for (auto val : arr){
        sum += val;
    }
    cout << sum << endl;
        
    return 0;
    
}