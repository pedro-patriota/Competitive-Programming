#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second

int ms = 1e6 + 17;

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;   
    vector<int> sum (ms, 0);
    vector<int> freq(ms);
    for (int i = 1; i  < ms; i ++){
        sum[i] = i%10 + sum[i/10];
    }
    for (int i = 0; i < n ; i++){
        int v; cin >> v;  freq[v]++;
    }
    for (int i = ms - 1; i > 0; i--){
        int used = min(k, freq[i]);
        freq[i] -= used;
        freq[i - sum[i]] += used;
        k -= used;
        if (k == 0){
            cout << sum[i] << endl;
            return 0;
        }

    }
    cout << 0 << endl;
        
    return 0;
    
}