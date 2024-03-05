#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second
#define PB push_back

bool multiTest = true;

void solve(){
    int h, w, x1, x2, Y1, y2;
    cin >> h >> w >> x1 >> Y1 >> x2 >> y2;
    ii range1, range2; 
    range1 = make_pair(Y1, Y1);
    range2 = make_pair(y2, y2);

    bool alice_turn = true;
    while(x1 < x2 || max(x1, x2) == h){
        if (alice_turn){
            range1.first = max(1, range1.first - 1);        
            range1.second = min(w, range1.second + 1);        

            x1++;
            if (range1.first <= range2.first && range1.second >= range2.second && x1 == x2){
                cout << "Alice" << endl;
                return;
            }
        }else{
            range2.first = max(1, range2.first - 1);        
            range2.second = min(w, range2.second + 1);        

            x2--;
            if (range2.first <= range1.first && range2.second >= range1.second && x1 == x2){
                cout << "Bob" << endl;
                return;
            }
        }
        alice_turn = !alice_turn;
    }
    cout << "Draw" << endl;
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1;
    if (multiTest) cin >> t;
    while(t--){
        solve();
    }
    return 0;
    
}