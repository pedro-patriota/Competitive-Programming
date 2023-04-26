#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll n, m;
vector<vector<bool>> arr;
vector<vector<bool>> arr2;
vector<vector<bool>> visited;
bool ans = false;

int bfs(int i, int j, vector<vector<bool>>& arr)
{
    queue<tuple<long long, long long>> q;
    q.push(make_tuple(i, j));
    visited[i][j] = true;
    vector<vector<int>> counter (n, vector<int>(m));
    while (!q.empty())
    {
        auto u = q.front();
        auto is = get<0>(u);
        auto js = get<1>(u);
        q.pop();
        
        if (is == n - 1 && js == m - 1)
        {
            ans = true;
            break;
        }
        if (is - 1 >= 0)
        {
            if (not visited[is - 1][js] && arr[is - 1][js] == true)
            {
                q.push(make_tuple(is - 1, js));
                counter[is-1][js] = counter[is][js] + 1;
                visited[is - 1][js] = true;
                
            }
        }
        if (is + 1 < n)
        {
            if (not visited[is + 1][js] && arr[is + 1][js] == true)
            {
                visited[is + 1][js] = true;
                counter[is + 1][js] = counter[is][js] + 1;
                q.push(make_tuple(is + 1, js));
            }
        }
        if (js - 1 >= 0)
        {
            if (not visited[is][js - 1] && arr[is][js - 1] == true)
            {
                visited[is][js - 1] = true;
                counter[is][js-1] = counter[is][js] + 1;
                q.push(make_tuple(is, js -1));
            }
        }
        if (js + 1 < m)
        {
            if (not visited[is][js + 1] && arr[is][js + 1] == true)
            {
                visited[is][js + 1] = true;
                counter[is][js + 1] = counter[is][js] + 1;
                q.push(make_tuple(is, js + 1));
                
            }
        }
    }
    return counter[n - 1][m-1];
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    arr = vector<vector<bool>>(n, vector<bool>(m));
    arr2 = vector<vector<bool>>(n, vector<bool>(m));
    visited = vector<vector<bool>>(n, vector<bool>(m, false));
    char point;
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < m; i++)
        {
            cin >> point;
            if (point == '.')
            {
                arr[j][i] = true;
            }
            else
            {
                arr[j][i] = false;
            }
        }
    }
    
    ll shortest_path = bfs(0, 0, arr);
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < m; i++)
        {
            cin >> point;
            if (point == '#')
            {
                arr2[j][i] = false;
                arr[j][i] = false;
            }else{
                arr2[j][i] = true;
            }
        }
    }
    visited = vector<vector<bool>>(n, vector<bool>(m, false));
    ll shortest_path2 = bfs(0, 0, arr2);
    visited = vector<vector<bool>>(n, vector<bool>(m, false));
    ll new_path = bfs(0, 0, arr);
    if (ans && shortest_path == new_path && shortest_path2 == new_path)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}