#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll min_play = LLONG_MAX;
ll n, x, y, obj, it = 1;

void backTracking(ll curr, ll num_play)
{
	if (curr == obj)
	{
		cout << num_play << endl;
		return;
	}

	ll leftMost = (curr) / 2;
	ll rightMost = (curr + (1 << (n))) / 2;

	if (curr % 2 == 0)
	{

		backTracking(rightMost, num_play + 1);
		backTracking(leftMost, num_play + 1);
	}

	return;
}

int main()
{
	ios ::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> x >> y;
	obj = x;

	backTracking(1 << (n - 1), 0);
	return 0;
}