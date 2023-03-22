#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll people;
int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    cin >> people;
    vector<ll> arr(people * 2);
    vector<vector<ll>> dif_arr(people * 2, vector<ll>(people * 2));
    pair<ll, pair<ll, ll>> max_val = make_pair(-1, make_pair(-1, -1));
    pair<ll, pair<ll, ll>> sec_max_val = make_pair(-1, make_pair(-1, -1));
    vector<bool> used(people * 2);

    for (ll i = 0; i < people * 2; i++)
    {
        cin >> arr[i];
    }
    for (ll i = 0; i < people * 2; i++)
    {
        for (ll j = i +1; j < people * 2; j++)
        {
            if (i != j)
            {
                if (abs(arr[i] - arr[j]) > max_val.first)
                {
                    max_val.first = abs(arr[i] - arr[j]);
                    max_val.second = make_pair(i, j);
                }
                if (abs(arr[i] - arr[j]) > sec_max_val.first && sec_max_val)
                {
                    sec_max_val.first = abs(arr[i] - arr[j]);
                    sec_max_val.second = make_pair(i, j);
                }
                dif_arr[i][j] = abs(arr[i] - arr[j]);
            }
            else
            {
                dif_arr[i][j] = INT_MAX;
            }
        }
    }
    used[max_val.second.first] = true;
    used[max_val.second.second] = true;

    vector<ll> total_diff(people * 2);
    ll counter = 0;
    for (ll i = 0; i < people * 2; i++)
    {
        if (not used[i])
        {
            pair<ll, ll> min_val = make_pair(INT_MAX, -1);
            for (ll j = i + 1; j < people * 2; j++)
            {
                if (not used[j])
                {

                    if (dif_arr[i][j] < min_val.first)
                    {
                        min_val.first = dif_arr[i][j];
                        min_val.second = j;
                    }
                }
            }
            counter += min_val.first;
            used[i] = true;
            used[min_val.second] = true;
        }
    }
    cout << counter;
}