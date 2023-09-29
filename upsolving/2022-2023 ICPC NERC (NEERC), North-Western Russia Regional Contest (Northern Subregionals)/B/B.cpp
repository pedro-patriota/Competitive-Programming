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

    int t, n, m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<vector<char>> table (n, vector<char> (m));
        vector<vector<int>> du, dd, dr, dl;
        dd = dr = dl = du = vector<vector<int>> (n, vector<int>(m));

        for(int i = 0; i < n ; i ++){
            for (int j = 0; j < m; j++){
                cin >> table[i][j];
            }
        }   
        for (int j = 0; j < m; j++){
            int vSize = 0;
            for(int i = 0; i < n ; i ++){
                if (table[i][j] == '.'){
                    vSize++;
                    du[i][j] = vSize;
                }else{
                    vSize = 0;
                }
            }   
            
        }
        for (int j = 0; j < m; j++){
            int vSize = 0;
            for(int i = n - 1; i >= 0 ; i--){
                if (table[i][j] == '.'){
                    vSize++;
                    dd[i][j] = vSize;
                }else{
                    vSize = 0;
                }
            }   
        }
        for(int i = 0; i < n ; i ++){
            int hSize = 0;
            for (int j = 0; j < m; j++){
                if (table[i][j] == '.'){
                    hSize++;
                    dl[i][j] = hSize;
                }else{
              
                    hSize = 0;
                }
            }
        }   
        for(int i = 0; i < n ; i ++){
            int hSize = 0;
            for (int j = m - 1; j >= 0; j--){
                if (table[i][j] == '.'){
                    hSize++;
                    dr[i][j] = hSize;
                }else{
                    hSize = 0;
                }
            }
        }
        int Hline = 0, Vline = 0;
        vector<ii> Hlines (n + 1, {0, 0});
        vector<ii> Vlines (m + 1, {0, 0});
        for(int i = 1; i <= n ; i ++){
            int maxVal = 0;
            for (int j = 0; j < m; j++){
                int aux = max(du[i-1][j], dr[i-1][j]);
                maxVal = max(maxVal, aux);
            }
            Hlines[i].X = max(Hlines[i - 1].X, maxVal);
        }   
        for(int i = n - 1 ; i >=0 ; i --){
            int maxVal = 0;
            for (int j = 0; j < m; j++){
                int aux = max(dd[i][j], dr[i][j]);
                maxVal = max(maxVal, aux);
            }
            Hlines[i].Y = max(Hlines[i + 1].Y, maxVal);
        }   
        for (int i = 0; i <= n; i++) Hline = max(Hlines[i].Y + Hlines[i].X, Hline);
        
        for(int j = 1; j <= m ; j ++){
            int maxVal = 0;
            for (int i = 0; i < n; i++){
                int aux = max(dl[i][j-1], du[i][j-1]);
                maxVal = max(maxVal, aux);
            }
            Vlines[j].X = max(Vlines[j - 1].X, maxVal);
        }   
        for(int j = m - 1 ; j >=0 ; j --){
            int maxVal = 0;
            for (int i = 0; i < n; i++){
                int aux = max(dr[i][j], du[i][j]);
                maxVal = max(maxVal, aux);
            }
            Vlines[j].Y = max(Vlines[j + 1].Y, maxVal);
        }   
        int ans;
        for (int i = 0; i <= m; i++) Vline = max(Vlines[i].Y + Vlines[i].X, Vline);
        ans =  max(Vline, Hline);


        

        
        cout << ans << endl;   


        

    }
    
    
    return 0;
    
}