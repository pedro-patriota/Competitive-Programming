#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
vector<vector<int>>ratMap;
vector<pair<pair<int, int>, int>>ratPos;
ll d, n, x, y, pop;

void color(ll x, ll y, ll pop){
    ll max_x_left = x - d < 0 ? 0 : x -d; 
    ll max_x_right = x + d > 1024 ? 1024 : x + d; 
    ll max_y_bottom = y - d < 0 ? 0 : y -d; 
    ll max_y_top = y + d > 1024 ? 1024 : y + d; 

    for (ll i = max_x_left; i <= max_x_right; i++){
        for (ll j = max_y_bottom; j <= max_y_top; j++){
            ratMap[i][j] += pop;
        }
    }
    return;
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    ll scenarios;
    cin >> scenarios;
    for (ll i = 0; i < scenarios; i++){
        ratMap = vector<vector<int>>(1025, vector<int>(1025));
        cin >> d;
        cin >> n;

        ratPos = vector<pair<pair<int, int>, int>>(n);
        for (ll j = 0; j < n; j++){
            cin >> x >> y >> pop;
            color(x, y, pop);
        }
        ll final_x, final_y, final_pop = 0;
        for (ll i = 0; i < 1025; i++){
            for (ll j = 0; j < 1025; j++){
                if (ratMap[i][j] > final_pop){
                    final_pop = ratMap[i][j];
                    final_x = i;
                    final_y = j;
                }
            }
        }
        cout << final_x << " " << final_y << " " << final_pop << endl;


    }
        
    
    
}