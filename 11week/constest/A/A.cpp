#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const ll MAX_VAL = 1e9 + 17;
int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    string S, W;
    cin >> S >> W;
    vector<ll> counterW;
    vector<char> counterCharW;

    vector<ll> counterS;
    vector<char> counterCharS;
    
    counterW.push_back(1);
    counterCharW.push_back(W[0]);
    
    set<char> count_letters;
    count_letters.insert(W[0]);
    
    ll aux = 0;

    for (ll i = 1; i < W.size(); i++){
        if (W[i] == W[i-1]){
            counterW[aux]++;
        }else{
            counterCharW.push_back(W[i]);
            counterW.push_back(1);
            count_letters.insert(W[i]);
            aux++;
        }
    }

    aux = 0;
    for (ll i = 0; i < S.size(); i++){
        if (not count_letters.count(S[i])) continue;
        if (i == 0){
            counterS.push_back(1);
            counterCharS.push_back(S[i]);
        
        }else{
            if (S[i] == S[i-1]){
                counterS[aux]++;
            }else{
                counterCharS.push_back(S[i]);
                counterS.push_back(1);
                aux++;
            }
        }
    }

    ll ans = 1;
    /* if (counterCharS.size() != counterCharW.size()){
        cout << 0;
        return 0;
    } */
    ll cache = counterCharW.size();

    ll res = 0;
    for (ll i = 0; i < counterCharS.size(); i++){
        aux = 1;
        if (counterCharS[i] == counterCharW[i%cache]){
            for (ll val = 0; val < counterW[i%cache]; val++){
                aux = (aux * (counterS[i] - val))%MAX_VAL;
            }
            aux /= counterW[i%cache];
            ans = (ans*aux) % MAX_VAL;

            if ((i+1)%cache == 0){
                res += ans;
                ans = 1;
            }
        }else{
            ans = 1;
        }
    }

    cout << res;


    
        
    return 0;
    
}