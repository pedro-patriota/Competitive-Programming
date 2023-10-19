#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second

bool multiTest = true;
const int mx = 1e5 + 17;
bool sieve[mx];

set<int> b;
void getFact(int n){
	for(int p = 2; p*p <= n; p++){
		if(n % p == 0){
			int exp = 0;
			while(n % p == 0){
				exp++;
				n /= p;
			}
			b.insert(p);
		}
	}
	if(n > 1) b.insert(n);
	return primes;
}

void solve()
{
    int n;
    int m;
    cin >> n >> m;
    b = set<int>();
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        getFact(arr[i]);
    }

    for (auto v : b)
    {
        if (v != 1)
        {
            if (not sieve[v])
            {
                sieve[v] = true;
                for (int j = 2 * arr[i]; j < m + 17; j += arr[i])
                {
                    sieve[v] = true;
                }
            }
        }
    }
    int qnt = 1;
    for (int i = 2; i <= m; i++){
        if (not sieve[i]){
            qnt++;
        }
    }
    cout << qnt << endl;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 1)
        {
            if (sieve[arr[i]])
            {
                sieve[arr[i]] = false;
                for (int j = 2 * arr[i]; j < m + 17; j += arr[i])
                {
                    sieve[j] = false;
                }
            }
        }
    }

}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1;
    if (multiTest)
        cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}