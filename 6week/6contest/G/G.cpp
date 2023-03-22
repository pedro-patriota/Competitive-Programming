#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll counter = 0;
vector<vector<vector<pair<int, int>>>> adj;
bool** visited;
void dfs(pair<int, int> u){
    if (u.first == n-1 && u.second == n-1){
        counter++;
    }   
    for (auto val : adj[u.first][u.second]){
        dfs(val);
    }
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    adj= vector<vector<vector<pair<int, int>>>>(n, vector<vector<pair<int, int>>>(n));
    visited = new bool*[n];
    for (int i = 0; i < n; i++){
        visited[i] = new bool;
    }
    char arr [n][n];

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    if (arr[0][0] == '*' || arr[n-1][n-1] == '*'){
        cout << 0;
        return 0;
    }
    for (ll j = 1; j < n; j++)
    {
        if (arr[0][j] == '.')
        {
            if (arr[0][j - 1] == '.')
            {
                adj[0][j-1].push_back(make_pair(0, j));
            }
        }
    }
    for (ll i = 1; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (arr[i][j] == '.')
            {
                if (j - 1 >= 0)
                {

                    if (arr[i][j - 1] == '.')
                    {
                        adj[i][j-1].push_back(make_pair(i, j));
                    }
                }

                if (arr[i - 1][j] == '.')
                {
                    adj[i - 1][j].push_back(make_pair(i, j));
                }
            }
        }
    }
    vector<ll>arr_counter (n);
    
    dfs(make_pair(0, 0));
    cout << counter;
}