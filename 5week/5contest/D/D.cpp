#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll true_facts, bad_facts, obj, init;
bool found;
string val, worse_val;
vector<vector<ll>>adj;
vector<vector<ll>>alter_adj;
vector<bool> visited;
void dfs(ll u){
    if (u == obj){
        found = true;
        return;
    }
    for (auto val : adj[u]){
        if (not visited[val]){
            visited[val] = true;
            dfs(val);
        }
    }
}
void alter_dfs(ll u){
    if (u == obj){
        found = true;
        return;
    }
    for (auto val : alter_adj[u]){
        if (not visited[val]){
            visited[val] = true;
            alter_dfs(val);
        }
    }
}


int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> true_facts >> bad_facts;
    map<string, ll> aux;
    adj = vector<vector<ll>>(193);
    alter_adj = vector<vector<ll>>(193);
    ll counter = 0;
    for (ll i = 0; i < true_facts; i++){
        string aux_val;
        cin >> val;
        cin >> aux_val;
        cin >> aux_val;
        cin >> aux_val;
        cin >> worse_val;
        if (!aux.count(val)){
            aux[val] = counter;
            counter++;
        }
        if (!aux.count(worse_val)){
            aux[worse_val] = counter;
            counter++;
        }
        ll index = aux[val];
        ll worse_index = aux[worse_val];

        adj[index].push_back(worse_index);
        alter_adj[worse_index].push_back(index);
    }

    for (ll i = 0; i < bad_facts; i++){
        string aux_val;
        cin >> val;
        cin >> aux_val;
        cin >> aux_val;
        cin >> aux_val;
        cin >> worse_val;
        if (!aux.count(val)){
            aux[val] = counter;
            counter++;
        }
        if (!aux.count(worse_val)){
            aux[worse_val] = counter;
            counter++;
        }
        found = false;
        visited = vector<bool>(counter);
        obj = aux[worse_val];
        init = aux[val];
        dfs(init);
        if (found){
            cout << "Fact\n";
        }else{
            visited = vector<bool>(counter);
            alter_dfs(init);
            if (found){
                cout << "Alternative Fact\n";
            }else{
                cout << "Pants on Fire\n";
            }
        }

    }
    

}