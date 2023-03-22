#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll len, t, counter;
string input;
int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cin >> len >> t;
    cin >> input;
    ll counter_aux, aux_t;
    aux_t = t;
    vector<bool> arr(len);
    vector<bool> aux(len);
    for (ll i = 0; i < len; i++){
        if (input[i] == 'B'){
            arr[i] = true;
            aux[i] =true;
        }else{
            arr[i] = false;
            aux[i] = false;
        }
    }
    for (ll i = 0; i < t; i++){
        for (ll j = len - 2; j >= 0; j--){
            if (aux[j]){
                if (!aux[j+1]){
                    swap(arr[j], arr[j+1]);
                }
            }
        }
        aux = arr;
        
    }
    for (ll i = 0; i < len; i++){
        if (arr[i] == true){
            cout << 'B';
        }else{
            cout << 'G';
        }
    }
    
    
}