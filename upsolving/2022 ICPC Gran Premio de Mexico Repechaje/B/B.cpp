#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define pii pair<int, int>
#define X first
#define Y second

int n, m;
vector<vector<bool>> visited;
vector<vector<int>> maze;
pii start, finish;

bool isPos(int x, int y){
    if (x >= n || y >= m) return false;
    if (x < 0 || y < 0) return false;

    return true;
}

int best = 11;
void dfs(int x, int y, set<int> tags){
    if (not isPos(x, y)) return;
    if (visited[x][y]) return;

    visited[x][y] = true;
    tags.insert(maze[x][y]);
    cout <<" " << x << " " << y << " " <<tags.size() << endl;

    if (x == finish.X && y == finish.Y) {
        best = min(best, (int) tags.size());
        return;
    }
    
    dfs (x, y + 1, tags);
    dfs (x+1, y, tags);
    dfs (x - 1, y, tags);
    dfs (x, y - 1, tags);

}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    maze.resize(n, vector<int> (m));
    visited.resize(n, vector<bool> (m, false));

    int x, y;
    cin >> x >> y;
    x--; y--;
    start = {x, y};
    cin >> x >> y;
    x--; y--;
    finish = {x, y};


    for (int i = 0; i < n ; i ++){
        for (int j = 0; j < m ;  j++){
            cin >> maze[j][i];
        }
    }
    set<int> a;
    dfs(start.X, start.Y, a);
    cout << best << endl;



    
        
    return 0;
    
}