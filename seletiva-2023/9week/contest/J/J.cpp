#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    ll N, M, setM, aux = 1;
    cin >> N >> M;
    vector<ll> arrN (N);
    vector<ll> prefix;
    for (ll i = 0;  i < N;i ++){
        cin >> arrN[i];
    }
    ll i = 0;
    ll count = 0;
    while (i < N){
        if (aux == 1){
            setM = ((1 + M)*M)/2;
        }else{
            setM = (((M*aux + (((aux-1)*(M)))+1)*(M)))/2;
        }

        ll sumN = 0;
        for (ll j = i; j < N; j++){
            sumN += arrN[j]; 
            i = j + 1;
            if (sumN >= setM){
                count += 1;
                break;
            }
        }

        aux++;
    }

    cout << count;
    
    
    
}