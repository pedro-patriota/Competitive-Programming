#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m;
int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
     ofstream fout ("speeding.out");
    ifstream fin ("speeding.in"); 

    fin >> n >> m;
    vector<ll> speed_limit(n);
    vector<ll> km_speed_limit(n);
    vector<ll> speed_cow(m);
    vector<ll> km_speed_cow(m);
    ll km, vel;
    fin >> km >> vel;
    speed_limit[0] = vel;
    km_speed_limit[0] = km;
    for (ll i = 1; i < n; i++)
    {
        fin >> km >> vel;
        km_speed_limit[i] = km_speed_limit[i - 1] + km;
        speed_limit[i] = vel;
    }
    fin >> km >> vel;
    speed_cow[0] = vel;
    km_speed_cow[0] = km;
    for (ll i = 1; i < m; i++)
    {
        fin >> km >> vel;
        km_speed_cow[i] = km_speed_cow[i - 1] + km;
        speed_cow[i] = vel;
    }
    ll max = 0;
    for (ll i = 1; i <= 100; i++)
    {
        auto act_limit = lower_bound(km_speed_limit.begin(), km_speed_limit.end(), i);
        auto act_speed = lower_bound(km_speed_cow.begin(), km_speed_cow.end(),i );

        ll limit = speed_limit[act_limit - km_speed_limit.begin()];
        ll speed = speed_cow[act_speed - km_speed_cow.begin()];
        if ((speed - limit) > max)
        {
            max = speed - limit;
        }
        i = min(*act_limit, *act_speed);
    }
    fout << max;
}