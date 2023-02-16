#include <bits/stdc++.h>
using namespace std;
long long test_cases, height, width;
vector<deque<long long>> adj;
vector<vector<char>> table;
vector<bool> visited;
map <char, long long> record;
char lan;
void dfs(long long u){
    for (auto val : adj[u]){
        if (not visited[val]){
            visited[val] = true;
            dfs(val);
        }
    }
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> test_cases;
    for (long long test = 0; test < test_cases; test++){
        cin >> height >> width;
        adj = vector<deque<long long>>(height*width);
        table = vector<vector<char>> (height, vector<char>(width));
        record = map<char, long long>();
        visited = vector<bool> (height*width, false);
        for (long long i = 0; i < height; i++){
            
            for (long long j = 0; j < width; j++){
                cin >> table[i][j];
                if (i > 0){
                    if (table[i][j] == table[i-1][j]){
                        adj[(i-1)*width + j].push_back(i*width + j);
                        adj[(i)*width + j].push_back((i-1)*width + j);
                    }
                    if (j > 0){
                        if (table[i][j] == table[i][j-1]){
                            adj[i*width + j].push_back(i*width + j-1);
                            adj[i*width + j-1].push_back(i*width + j);
                        }
                    }
                    
                }else{
                    if (j > 0){
                        if (table[i][j] == table[i][j-1]){
                            adj[i*width + j].push_back(i*width + j-1);
                            adj[i*width + j-1].push_back(i*width + j);
                        }
                    }
                }
            }
        }
        for (long long i = 0; i < height; i++){
            
            for (long long j = 0; j < width; j++){
                if (not visited[i*width + j]){
                    dfs( i*width + j);
                    record[table[i][j]]++;
                }

            }
        }
        multimap<long long, char, greater<long long>> aux;
        for (auto it : record){
            aux.insert(make_pair(it.second, it.first));
        }
        cout << "World #" << test +1 << "\n";
        for (auto it : aux){
            cout << it.second << ": "<< it.first << "\n";
        }
    }
    
}