#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'



int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    ll n, k, feel;
    string op;
    cin >> n >> k;
    cin >> op;
    char next_step = 'L';
    for (int i = 0; i < n; i++){
        if (op[i] == next_step){
            if (next_step == 'L'){
                next_step = 'R';
            }else{
                next_step = 'L';
            }
        }else{
            feel++;
        }
    }
    cout << max((ll) 0, k-feel);
        
    return 0;
    
}