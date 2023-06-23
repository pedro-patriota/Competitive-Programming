#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
vector<vector<pair<int, double>>> adj;
vector<vector<double>> conversion_matrix;
vector<bool> visited;
int from;

void dfs(int u, double conv)
{
    for (auto val : adj[u])
    {
        if (not visited[val.first])
        {
            visited[val.first] = true;
            conversion_matrix[from][val.first] = conv * val.second;
            dfs(val.first, conv * val.second);
        }
    }
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    ll n, q;
    cin >> n >> q;
    adj = vector<vector<pair<int, double>>>(n * 2);
    conversion_matrix = vector<vector<double>>(2 * n, vector<double>(2 * n, -1));

    int counter = 0;
    map<string, int> units;
    string name_unit, trash, to_name_unit;
    double conversion, value;
    for (int i = 0; i < n; i++)
    {
        cin >> trash >> name_unit >> trash >> conversion >> to_name_unit;
        if (not units.count(name_unit))
        {
            units[name_unit] = counter;
            counter++;
        }
        if (not units.count(to_name_unit))
        {
            units[to_name_unit] = counter;
            counter++;
        }
        int id1 = units[name_unit];
        int id2 = units[to_name_unit];
        adj[id1].push_back(make_pair(id2, conversion));
        adj[id2].push_back(make_pair(id1, (double)1 / conversion));
    }

    for (int i = 0; i < q; i++)
    {
        cin >> value >> name_unit >> trash >> to_name_unit;
        int id1 = units[name_unit];
        int id2 = units[to_name_unit];
        if (id1 == id2){
             cout  << setprecision(20) << value << endl;
            continue;
        }
        if (conversion_matrix[id1][id2] == -1)
        {
            visited = vector<bool>(2 * n, false);
            from = id1;
            dfs(id1, 1);
            if (conversion_matrix[id1][id2] != -1)
            {
                cout  << setprecision(20) << value*conversion_matrix[id1][id2] << endl;
            }
            else
            {
                conversion_matrix[id1][id2] = -2;
                cout << "impossible" << endl;
            }
        }
        else if (conversion_matrix[id1][id2] == -2)
        {
            cout << "impossible" << endl;
        }
        else
        {
            cout << setprecision(20) << value*conversion_matrix[id1][id2] << endl;
        }
    }

    return 0;
}