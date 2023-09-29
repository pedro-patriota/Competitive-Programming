#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;
    int id = 1, king = 1;
    vector<vector<int>> sons (q + 7);
    vector<int> dad (q + 7);
    vector<int> nextSon (q + 7, 0);
    vector<bool> alive (q + 7);

    alive[king] = 1;

    for (int i = 0; i < q; i++)
    {
        int t, x, currLevel;
        cin >> t >> x;
        if (t == 1)
        {
            id++;
            dad[id] = x;
            sons[x].push_back(id);
            alive[id] = 1;
        }
        else
        {
            alive[x] = 0;

            while (not alive[king]){
                int next = nextSon[king];
                if (next == sons[king].size()) king = dad[king];
                else{
                    nextSon[king]++;
                    king = sons[king][next];
                }
            }
            cout << king << endl;
        }
    }

    return 0;
}