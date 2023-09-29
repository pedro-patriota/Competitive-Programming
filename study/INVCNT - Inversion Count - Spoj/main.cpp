#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second

// Fenwick Tree
const int MX = 2e5+5;
vector<ll> BIT;
int n, q;

ll qry(int i){ // [1,i] 1 indexado
	ll ret = 0;
	for(; i > 0; i -= i & -i){
		ret += BIT[i];
	}
	return ret;
}

ll qryRange(int l, int r){ // 1 indexado inclusivo
	ll qr = qry(r);
	ll ql = qry(l-1);
	return qr-ql;
}
void increment(ll i, ll v){ // 1 indexado (+= v)
	for(; i <= n; i += i & -i){
		BIT[i] += v;
	}
}
void build(const vector<ll>& nums){
	for(int i = 0; i < nums.size(); i++){
		increment(i+1,nums[i]);
	}
}




int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
         cin >> n;
        BIT = vector<ll>(n + 17, 0);

        vector<ll> arr (n);
        for (int i =0; i < n; i++) cin >> arr[i];
        vector<ll> b = arr;
        sort(b.begin(), b.end());
        map<ll, int> label;
        int cnt = 1;
        for (int i  = 0 ; i  < n ; i++){
            label[b[i]] = cnt++;
        }
        for (int i = 0; i < n ; i ++){
            arr[i] = label[arr[i]];
        }
        ll ans = 0;
        for (int i = n - 1; i >= 0; i--){
            increment(arr[i], 1);
            ans += qry(arr[i] - 1);
        }
        cout << ans << endl;


    }
        
    return 0;
    
}