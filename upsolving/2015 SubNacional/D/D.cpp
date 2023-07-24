#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int l, c;
vector<vector<string>> alfa;
vector<ll>sumAlfaH;
vector<ll>sumAlfaV;
vector<map<string, ll>> mapH;
vector<map<string, ll>> mapV;

void deleteVar(string var, ll val){
    for (int i = 0; i < l ; i++){
        if (mapH[i].count(var)) {
            auto it = *mapH[i].find(var);
            ll freq = it.second;

            //cout << "Achei esse "<< var << " e tirei o valor da equcao " << sumAlfaH[i] << " com " << val*freq << endl;

            sumAlfaH[i] -= val*freq;
            mapH[i].erase(var);
         
        }
    }
    for (int i = 0; i < c ; i++){
        if (mapV[i].count(var)) {
            auto it = *mapV[i].find(var);
            ll freq = it.second;

            //cout << "Achei esse "<< var << " e tirei o valor da equcao " << sumAlfaV[i] << " com " << val*freq << endl;

            sumAlfaV[i] -= val*freq;
            mapV[i].erase(var);
       
        }
    }
}

vector<pair<string, ll>> valuesArr;

void findVar(){
    ll freq, answer;
    string var;
    for (int i = 0; i < l ; i++){
        if (mapH[i].size() == 1) {
            auto it  = *mapH[i].begin();
            var = it.first;
            freq = it.second;
            answer = sumAlfaH[i];

            valuesArr.push_back(make_pair(var, answer/freq));
            deleteVar(var, answer/freq);
            return;
        }

    }
    for (int i = 0; i < c ; i++){
        if (mapV[i].size() == 1) {
            auto it  = *mapV[i].begin();
            var = it.first;
            freq = it.second;
            answer = sumAlfaV[i];

            valuesArr.push_back(make_pair(var, answer/freq));
            deleteVar(var, answer/freq);
            return;
        }
    }
}


int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    cin >> l >> c;
    
    mapH = vector<map<string, ll>> (l);
    mapV = vector<map<string, ll>> (c);
    sumAlfaH = vector<ll> (l);
    sumAlfaV = vector<ll> (c);
    string var;
    set<string> diffVar;
    for (int i  = 0; i < l; i++){
        for (int j = 0; j < c; j++){
            cin >> var;
            diffVar.insert(var);
            mapH[i][var]++; 
            mapV[j][var]++; 
        }
        cin >> sumAlfaH[i];
    }
    for (int j = 0; j < c; j++){
        cin >> sumAlfaV[j];
    }
    while (valuesArr.size() !=  diffVar.size()){
        findVar();
    }
    sort(valuesArr.begin(), valuesArr.end());

    for (auto [var, val] :  valuesArr){
        cout << var << " " << val << endl;
    }   

    


    return 0;
    
}