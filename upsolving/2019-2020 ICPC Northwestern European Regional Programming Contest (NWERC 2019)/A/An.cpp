#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    ll n, w, k, competitor;
    cin >> n >> w;
    vector<ll> rank (w + 17, 1);
    vector<ll> score (n, 0);
    vector<ll> last (w + 17);
    vector<ll> sum (w + 17);
    vector<ll> delta (n, 0);

    for (ll i = 0; i < w; i++){
        cin >> k;
        map<ll, ll> pointFreq;
        vector<ll> competitors;
        for (ll j = 0; j < k; j++){
            cin >> competitor;
            competitor--;
            ll scoreY = score[competitor];

            sum[scoreY] += rank[scoreY] * (i - last[scoreY]);
            last[scoreY] = i;

            sum[scoreY + 1] += rank[scoreY + 1]*(i - last[scoreY + 1]);
            last[scoreY + 1] = i;

            pointFreq[scoreY]++;
            delta[competitor] += sum[scoreY] - sum[scoreY + 1];
            score[competitor]++;
        }
        for (auto [scoreY, freq] : pointFreq){
            rank[scoreY] += freq;
        }

    }
    for (competitor = 0; competitor < n; competitor ++){
        ll scoreY = score[competitor];

        sum[scoreY] += rank[scoreY] * (w - last[scoreY]);
        last[scoreY] = w;
        delta[competitor] += sum[scoreY];
        cout << setprecision(30) << (double) delta[competitor]/w;
    cout << endl; 
        
    }

    return 0;
    
}