#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    vector<int>T(n);
    vector<int>P(n);
    for (int i = 0; i < n; i++){
        cin >> T[i];
    }
    for (int i = 0; i < n; i++){
        cin >> P[i];
    }
    vector<char>choosen(n);
    multimap<int, int> choosenP;
    multimap<int, int> choosenT;
    ll sum = 0;
    for (int i = 0; i < n; i++){
        if (T[i] > P[i]){
            choosenT.insert(make_pair(i,abs(T[i] - P[i]) ));
            choosen[i] = 'T';
        }else{
            choosenP.insert(make_pair(i,abs(T[i] - P[i]) ));
            choosen[i] = 'P';
        }
        sum += max(P[i], T[i]);
    }
    multimap<int, int> inv_choosenP;
    multimap<int, int> inv_choosenT;

    if (choosenT.size() < a){
        for (auto val : choosenP){
            inv_choosenP.insert(make_pair(val.second, val.first));
        }
        auto it  = inv_choosenP.begin();
        for (int i = 0; i < (a - choosenT.size()); i++){
            choosen[it->second] = 'T';
            sum -= it->first;
            it++;
        }
        
    }
    if (choosenP.size() < b){
        for (auto val : choosenT){
            inv_choosenT.insert(make_pair(val.second, val.first));
        }
        auto it  = inv_choosenT.begin();
        for (int i = 0; i < (b - choosenP.size()); i++){
            sum -= it->first;
            choosen[it->second] = 'P';
            it++;
        }
    }
    cout << sum << endl;
    for (int i = 0; i < n; i++){
        cout << choosen[i] << " ";
    }

    
        
    return 0;
    
}