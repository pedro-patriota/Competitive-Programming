#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second
#define PB push_back

bool multiTest = false;

void solve(){
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i< n; i++){
        cin >> arr[i];
    }
    int i = 0, j = n-1, op = 0;
    while (j > i){
        if (arr[i] == arr[j]){
            i++;
            j--;
            continue;
        }
        op++;
        if (arr[i] < arr[j]){
            arr[i+1] += arr[i];
            i++;
        }else{
            arr[j-1] += arr[j];
            j--;
        }
    }
    cout << op << endl;

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