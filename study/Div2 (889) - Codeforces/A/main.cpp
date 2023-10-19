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

    
    int t; cin >> t;
    while (t--){
        int n, m = 1;
        cin >> n;
        for (int i = 0; i < n; i++){
            int v; cin >> v;
            if (v == m){
                m++;
            }
            m++;
        }
        cout << m - 1 << endl;

    }
        
    return 0;
    
}