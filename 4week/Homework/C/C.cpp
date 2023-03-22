#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll people, relations;
string p1, p2;
vector<vector<ll>> adj;
vector<vector<ll>> dist;
map<string, ll> aux;

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    ll test = 1;
    while (true)
    {
        cin >> people >> relations;
        adj = vector<vector<ll>>(people, vector<ll>(people, false));
        dist = vector<vector<ll>>(people, vector<ll>(people));
        aux = map<string, ll>();
        ll coounter = 0, largest = -1;

        if (not people && not relations)
        {
            break;
        }
        for (ll relation = 0; relation < relations; relation++)
        {
            cin >> p1 >> p2;
            if (!aux.count(p1))
            {
                aux[p1] = coounter;
                coounter++;
            }
            if (!aux.count(p2))
            {
                aux[p2] = coounter;
                coounter++;
            }

            adj[aux[p1]][aux[p2]] = true;
            adj[aux[p2]][aux[p1]] = true;
        }
        for (ll i = 0; i < people; i++)
        {

            for (ll j = 0; j < people; j++)
            {
                if (i == j)
                    dist[i][j] == 0;
                else if (adj[i][j])
                    dist[i][j] = adj[i][j];
                else
                    dist[i][j] = 10e16;
            }
        }
        for (ll k = 0; k < people; k++)
        {
            for (ll i = 0; i < people; i++)
            {
                for (ll j = 0; j < people; j++)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    dist[j][i] = dist[i][j];
                }
            }
        }
        bool no_conect = false;
        for (ll i = 0; i < people; i++)
        {

            for (ll j = 0; j < people; j++)
            {
                if (dist[i][j] > largest)
                {
                    largest = dist[i][j];
                }
                if (dist[i][j] == 10e6)
                {
                    no_conect = true;
                    break;
                }
            }
            if (no_conect)
            {
                break;
            }
        }
        cout << "Network " << test << ": ";
        if (!no_conect)
        {
            cout << largest << "\n";
        }
        else
        {
            cout << "DISCONNECTED\n";
        }
        test++;
    }
}