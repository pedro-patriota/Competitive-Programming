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
    int n, x, y, mx = 0; cin >> n;
    vector<ii> ranges (n);
    for (int i = 0; i < n ; i ++){
        cin >> x >> y;
        ranges[i] = {x, y};
        mx = max(mx, y);
    }
    sort(ranges.begin(), ranges.end());
    priority_queue<ii, vector<ii>, greater<ii>> pq; 
    int best = 0;

    for (auto [begin, end] : ranges){
        while (!pq.empty() && pq.top().first <= begin){
            best = max(best, pq.top().second);
            pq.pop();
        }
        pq.push({end, best + 1});
    }
    while (!pq.empty()){
        best = max(best, pq.top().second);
        pq.pop();
    }
    cout << best << endl;
    
    


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