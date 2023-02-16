#include <bits/stdc++.h>
using namespace std;
long long test_cases, n, m, counter_G;
string row;
vector<vector<char>> table;
vector<vector<bool>> visited;
vector<tuple<long long, long long>> table_B;
vector<tuple<long long, long long>> table_G;

char letter;
void bfs(long long sourceI, long long sourceJ)
{
    queue<tuple<long long, long long>> q;
    q.push(make_tuple(sourceI, sourceJ));
    visited[sourceI][sourceJ] = true;
    if (table[sourceI][sourceJ] == '#'){
        return;
    }
    while (!q.empty())
    {
        auto u = q.front();
        auto i = get<0>(u);
        auto j = get<1>(u);
        q.pop();
        if (table[i][j] == 'G'){
            counter_G--;
        }
        if (i + 1 < n)
        {
            if (not visited[i + 1][j] && table[i + 1][j] != '#')
            {
                q.push(make_tuple(i + 1, j));
                visited[i + 1][j] = true;
            }
        }
        if (i - 1 >= 0)
        {
            if (not visited[i - 1][j] && table[i - 1][j] != '#')
            {
                q.push(make_tuple(i - 1, j));
                visited[i - 1][j] = true;
            }
        }
        if (j + 1 < m)
        {
            if (not visited[i][j + 1] && table[i][j + 1] != '#')
            {
                q.push(make_tuple(i, j + 1));
                visited[i][j + 1] = true;
            }
        }
        if (j - 1 >= 0)
        {
            if (not visited[i][j - 1] && table[i][j - 1] != '#')
            {
                q.push(make_tuple(i, j - 1));
                visited[i][j - 1] = true;
            }
        }
    }
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cin >> test_cases;
    for (long long test = 0; test < test_cases; test++)
    {
        cin >> n >> m;
        table = vector<vector<char>>(n, vector<char>(m));
        visited = vector<vector<bool>>(n, vector<bool>(m, false));
        table_B = vector<tuple<long long, long long>>();
        table_G = vector<tuple<long long, long long>>();
        counter_G = 0;
        for (long long i = 0; i < n; i++)
        {
            for (long long j = 0; j < m; j++)
            {
                cin >> table[i][j];
                if (table[i][j] == 'B')
                {
                    table_B.push_back(make_tuple(i, j));
                }
                if (table[i][j] == 'G')
                {
                    counter_G++;
                }
            }
        }
        for (auto t : table_B)
        {
            auto i = get<0>(t);
            auto j = get<1>(t);
            if (i + 1 < n)
            {
                table[i + 1][j] = '#';
            }
            if (i - 1 >= 0)
            {
                table[i - 1][j] = '#';
            }
            if (j + 1 < m)
            {
                table[i][j + 1] = '#';
            }
            if (j - 1 >= 0)
            {
                table[i][j - 1] = '#';
            }
        }

        bfs(n - 1, m - 1);

        if (counter_G == 0)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
}