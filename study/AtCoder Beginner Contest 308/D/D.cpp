#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define PB push_back
#define Y second


bool multiTest = false;
string s = "snuke";
map<char, int> aux;
int h, w;
bool isPos = false;
vector<vector<char>> adj;
vector<vector<bool>> vis;

vector<ii> dir(int i, int j){
    return {{i + 1, j}, {i, j+1}, {i-1, j}, {i, j-1}};
}
char next(char u){
    int q = aux[u];
    return s[(q + 1)%s.size()];
}


void bfs(){ 
    queue<ii> q;
    vis[0][0] = true;
    q.push({0, 0});

    while (not q.empty()){
        int lvSZ = q.size();
        while (lvSZ--){
            auto [i, j] = q.front();
            q.pop();
            if (i == h -1 && j == w-1){
                isPos = true;
                break;
            }

            char now = adj[i][j];
            for (auto [ni, nj] : dir(i, j)){
                if (ni < 0 || nj < 0) continue;
                if (ni == h || nj == w) continue;
                
                if (not vis[ni][nj] && next(now) == adj[ni][nj]){
                    vis[ni][nj] = true;
                    q.push({ni, nj});
                }

            }
            
        }
        if (isPos) break;
    }

}


void solve(){
    cin >> h >> w;
    adj.resize(h, vector<char>(w));
    vis.assign(h, vector<bool>(w, false));
    for (int i = 0; i < s.size(); i++){
        aux[s[i]] = i;
    }

    for (int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> adj[i][j];
        }
    }
    bfs();
    if (isPos){
        cout << "yes" << endl;
    }else{
        cout << "no" << endl;
    }

}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1;
    if (multiTest) cin >> t;
    while(t--){
        solve();
    }
    return 0;
    
}