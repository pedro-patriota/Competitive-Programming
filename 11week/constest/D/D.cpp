#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    ll N, M, T, maxX, minX , maxY, minY, x = 0, y = 0;
    char op;
    cin >> N >> M;
    maxX = maxY = minX = minY= 0;

    cin >> T;
    for (ll i = 0 ; i < T; i ++){
        cin >> op;
        if (op == 'C'){
            x++;
            if (x > maxX){
                maxX = x;
            }
        }else if (op == 'D'){
            y++;
            if (y > maxY){
                maxY = y;
            }
        }else if (op == 'B'){
            x--;
            if (x < minX){
                minX = x;
            }
        }else if (op == 'E'){
            y--;
            if (y < minY){
                minY = y;
            }
        }
    }
    if (abs(minX) >= N || maxX >= N){
        cout << 0;
        return 0;
    }
    if (abs(minY) >= M || maxY >= M){
        cout << 0;
        return 0;
    }
    ll ans = ((N + minX) - maxX)*((M + minY) - maxY);
    //cout << ans << endl;
    ans = 0;
    vector<int> val;
    vector<int> valY;
    for (ll i = 1; i <= N; i++){
        if (i + maxX <= N && i + minX >= 1){
            ans++;
            val.push_back(i+x);
        }
    }
    ll ans2 = 0;
    for (ll i = 1; i <= M; i++){
        if (i + maxY <= M && i + minY >= 1){
            ans2++;
            val.push_back(i+y);
        }
    }
    cout << ans2*ans << endl;
    for (auto i : val){
        for (auto j : valY){
                cout << i << " " << j << endl;

        }
    }

    /* for (ll i = 1 + maxX; i <= N + minX; i++){
        for (ll j = 1 + maxY; j <= M + minY; j++){
        }
    } */

    
        
    return 0;
    
}