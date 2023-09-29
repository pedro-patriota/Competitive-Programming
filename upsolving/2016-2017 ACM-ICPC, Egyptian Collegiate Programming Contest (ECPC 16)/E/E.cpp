#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second

#define N 100010
vector<int> adj[N];
int dp[N];
int n;

void bfs(){
	queue<int> q;
	q.push(n);
	while(!q.empty()){
		auto f = q.front(); q.pop();
		for(int nb : adj[f]){
			if(dp[nb] == -1){
                dp[nb] = min(dp[nb], dp[f] + 1);
				q.push(nb);
            }
        }
	}
	return;
}

int main()
{

    ios ::sync_with_stdio(0);
    cin.tie(0);
    //freopen("jumping.in", "r", stdin);
    int t; 
    cin >> t;
    while (t--){   
        cin >> n;
        for (int i = 1; i <= n; i++) adj[i].clear();
        for (int i = 1 ; i <= n ; i ++){
            int d; cin >> d;
            if (d + i <= n){
                adj[d + i].push_back(i);
            }
            if (i - d >= 1){
                adj[i - d].push_back(i);
            }
        }
        memset(dp, -1, sizeof(dp));
        
        dp[n] = 0;
    
        bfs();
       
        for (int i = 1; i <= n; i++){
            cout << dp[i] << endl;
            
        }


    }
    
    return 0;
}