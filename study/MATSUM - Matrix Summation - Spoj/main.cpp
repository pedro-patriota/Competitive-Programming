#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second

// Fenwick Tree
const int MX = 2e5+5;
vector<vector<int>> BIT;
int n, q;

ll qry(int y, int i){ // [1,i] 1 indexado
	ll ret = 0;
	for(; i > 0; i -= i & -i){
		ret += BIT[y][i];
	}
	return ret;
}

ll qryRange(int y, int l, int r){ // 1 indexado inclusivo
	ll qr = qry(y, r);
	ll ql = qry(y, l-1);
	return qr-ql;
}
void increment(int y, int i, int v){ // 1 indexado (+= v)
    v = v - BIT[y][i];
	for(; i <= n; i += i & -i){
		BIT[y][i] += v;
	}
}



int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    int t;
    int x1, x2, y1, y2, v;
    int ans = 0;
    string in = "";
    cin >> t;
    while(t--){
        cin >> n;
        BIT.assign(n + 1, vector<int>(n + 1, 0));
        in = "";
        while (true){
            cin >> in;
            if (in == "END") break;
            if (in == "SET"){
                cin >> x1 >> y1 >> v; 
                increment(y1 + 1, x1 + 1, v);
            }else{
                ans = 0;
                cin >> x1 >> y1 >> x2 >> y2;
                for (int i = y1 + 1; i <= y2 + 1; i++){
                    ans += qryRange(i, x1+1, x2+1);
                }
                cout << ans << endl;
            }
        }
    }
    
    
        
    return 0;
    
}