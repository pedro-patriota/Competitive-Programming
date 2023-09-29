#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>

vector<vector<tuple<int, int, int>>> adj;
vector<ii> v;

vector<int> topologicalOrder(const vector<vector<tuple<int, int, int>>> &graph) {
	int n = (int) graph.size();
	std::vector<int> deg(n, 0);
	for(int i = 0; i < n; i++) {
		for(auto [j, price, prest] : graph[i]) {
			deg[j]++;
		}
	}
	std::vector<int> order;
	for(int i = 0; i < n; i++) {
		if(deg[i] == 0) {
            v[i] = {0, 0};
			order.push_back(i);
		}
	}
	for(int i = 0; i < (int) order.size(); i++) {
		int on = order[i];
		for(auto [to, price, prest] : graph[on]) {
			if(--deg[to] == 0) {
				order.push_back(to);
			}
		}
	}
	return order;
}
const int MAXN = 1e4 + 17;
vector<ll> dp (MAXN);
ll B, N;
int counter = 0;

ll knapsack(){
    int n = counter;
    for(int i = 0; i < n; i++){
        auto [w, val] = v[i];
        for(int sz = MAXN; sz >= w; sz--){
            dp[sz] = max(dp[sz],dp[sz-w]+ val);
        }
    }

    return dp[B];
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    cin >> B >> N;
    map<string, int> strToInt;
    vector<tuple<int, int, int, int>> input;

    for (int i = 0; i < N; i++){
        string toPizza, basePizza, ing;
        int price, prest, intToPizza, intBasePizza;
        cin >> toPizza >> basePizza >> ing >> price >> prest;
        if (not strToInt.count(toPizza)){
            strToInt[toPizza] = counter;
            counter++;
        }
        if (not strToInt.count(basePizza)){
            strToInt[basePizza] = counter;
            counter++;
        }
        
        
        intToPizza = strToInt[toPizza];
        intBasePizza = strToInt[basePizza];

        input.push_back({intToPizza, intBasePizza, price, prest});

    }

    adj.resize(counter);
    for (auto [intToPizza, intBasePizza, price, prest] : input){
        adj[intBasePizza].push_back({intToPizza, price, prest});
    }

    v.assign(adj.size(), {1e6, -1});

    auto res = topologicalOrder(adj);

    for (auto node : res){
        for (auto [to, price, prest] : adj[node]){
            auto [p, pr] = v[to];
            auto [fromP, fromPr] = v[node];

            if (price + fromP < p ) v[to] = {price + fromP, prest + fromPr};
            if (price + fromP == p) v[to] = {p, max(prest + fromPr, pr)};
        }
    }

    ll maxPr = knapsack();
    int minB = B;
    for (int i = B - 1; i >= 0; i--){
        if (dp[i]  == maxPr){
            minB = i;
        }else{
            break;
        }
    }

    cout << maxPr << endl;
    cout << minB << endl;
    
    

    
        
    return 0;
    
}