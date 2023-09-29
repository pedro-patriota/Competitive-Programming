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
    freopen("commandos.in","r",stdin);

    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<vector<vector<int>>> dp (12, vector<vector<int>> (12, vector<int>(12)));
        for (int i = 0; i < n ; i++){
            int f, y, x, p;
            cin >> f >> y >> x >> p; 
            dp[f][x][y] += p;
        }        
        
        for (int f = 10; f >= 1; f--){
            for (int x = 1; x <= 10; x++){
                for (int y = 1; y <= 10; y++){
                    dp[f][x][y] += max(dp[f+1][x][y], max(dp[f][x-1][y], dp[f][x][y-1]));
                }
            }
        }

        cout << dp[1][10][10] << endl;


    }
    
        
    return 0;
    
}
 