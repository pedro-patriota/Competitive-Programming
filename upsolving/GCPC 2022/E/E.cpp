#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'



int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    ll cur_day;
    cin >> cur_day;
    cur_day = min(cur_day, (ll) 1000);
    double fibo_pi[cur_day];
    fibo_pi[0] = 100.0;
    fibo_pi[1] = 0.0;
    for (int i = 2; i < cur_day; i++){
        fibo_pi[i] = (double) (fibo_pi[i-1] + fibo_pi[i-2])/2.0; 
    }
    double fibo_tau[cur_day];
    fibo_tau[0] = 0.0;
    fibo_tau[1] = 100.0;
    for (int i = 2; i < cur_day; i++){
        fibo_tau[i] = (double) (fibo_tau[i-1] + fibo_tau[i-2])/2.0; 
    }
        
    cout << setprecision(9)<< fibo_pi[cur_day - 1] << " " << fibo_tau[cur_day -1];
    return 0;
    
}