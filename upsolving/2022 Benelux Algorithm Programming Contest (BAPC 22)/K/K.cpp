#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll h, w;
int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cin >> h >> w;
    vector<vector<int>> map_num(h, vector<int>(w));
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            cin >> map_num[i][j];
        }
    }
        
    return 0;
    
}