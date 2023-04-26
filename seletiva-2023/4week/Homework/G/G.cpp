#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll test_cases, relations;
string p1, p2;
map<string, pair<string, ll>> table;
string findSet(string x){
    if (x==table[x].first) return x;
    return table[x].first = findSet(table[x].first);
}
void uniteSet(string a, string b){
    a = findSet(a);
    b = findSet(b);
    if (a != b){
        if (table[a].second > table[b].second){
            table[b].first = a;
            table[a].second += table[b].second;
            cout << table[a].second << "\n";
        }else{
            table[a].first = b;
            table[b].second += table[a].second;
            cout << table[b].second << "\n";
        }
    }else{
        cout << table[a].second << "\n";
    }
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cin >> test_cases; 
    for (ll test = 0; test < test_cases; test++){
        cin >> relations;
        table = map<string, pair<string, ll>>();
        for (ll rel = 0; rel < relations; rel++){
            cin >> p1 >> p2;
            if (not table.count(p1)){
                table[p1].first = p1;
                table[p1].second = 1;
            }
            if (not table.count(p2)){
                table[p2].first = p2;
                table[p2].second = 1;
            }
            uniteSet(p1, p2);

        }
    }
    
    
}