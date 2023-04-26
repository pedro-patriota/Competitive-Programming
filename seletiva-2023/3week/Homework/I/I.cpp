#include <bits/stdc++.h>
using namespace std;

long long test_cases, teams;
string n1, n2, n3;
map<string, set<string>> adj;
map<string, bool> visited;
map<string, long long> table;

void bfs(string source){
    queue<string> q;
    q.push(source);
    visited[source] = true;
    long long counter = 0;
    table[source] = 0;
    while (not q.empty()){
        string u = q.front();
        counter = table[u];
        q.pop();
        for (auto val : adj[u]){
            if (visited[val] == false){
                table[val] = counter  + 1;
                visited[val] = true;
                q.push(val);
            }
        }
    }
}
int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cin >> test_cases;
    for (long long test = 0; test < test_cases; test++){
        cin >> teams;
        adj = map<string, set<string>>();
        visited = map<string, bool>();
        table = map<string, long long>();

        for (long long team = 0; team < teams; team++){
            cin >> n1 >> n2 >> n3;
            
            adj[n1].insert(n2);
            adj[n2].insert(n1);
            
            adj[n1].insert(n3);
            adj[n3].insert(n1);

            adj[n2].insert(n3);
            adj[n3].insert(n2);
        }
        for (auto it : adj){
            visited[it.first] = false;
        }
        bfs("Ahmad");
        cout << visited.size() << "\n";
        multimap<long long, string>aux;
        for (auto it : visited){
            aux.insert(make_pair(table.count(it.first) ? table[it.first] : 10e16, it.first));
        }
        for (auto it : aux){
            if (it.first == 10e16){
                
            cout << it.second << " " <<  "undefined" << "\n";
            }else{
            cout << it.second << " " << it.first  << "\n";
                
            }
        }

    }
    
    
}