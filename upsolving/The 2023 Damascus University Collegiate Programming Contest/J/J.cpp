#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second

bool multiTest = true;

void solve()
{
  int n, ans = 0;
  cin >> n;
  map<int, int> freq;
  for (int i = 0; i < n; i++)
  {
    int p, msb;
    cin >> p;
    msb = __builtin_clz(p);
    ans = max(ans, ++freq[32 - msb]);
  }
  cout << ans << endl;
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