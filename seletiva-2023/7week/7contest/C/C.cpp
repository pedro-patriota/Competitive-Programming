#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll cities, stations, station, l, r, m;
vector<ll> arr_cities;
vector<ll> arr_stations;
bool is_possible(ll m){
    if (arr_stations[0] + m < arr_cities[0]){
        return false;
    }
    auto max_it =  upper_bound(arr_cities.begin(), arr_cities.end(), arr_stations[0] + m);
    auto min_it =  lower_bound(arr_cities.begin(), arr_cities.end(), arr_stations[0] - m);

    if (max_it == arr_cities.end() && min_it == arr_cities.begin()){
            return true;
    }
    for (ll i = 1; i < stations; i++){
        auto it1 = upper_bound(arr_cities.begin(), arr_cities.end(), arr_stations[i] + m);
        auto it2= lower_bound(arr_cities.begin(), arr_cities.end(), arr_stations[i] - m);

        if (it1 > max_it){
            max_it = it1;
        }
        if (it2 < min_it){
            min_it = it2;
        }
        if (max_it == arr_cities.end() && min_it == arr_cities.begin()){
            return true;
        }
    }
    return false;
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    cin >> cities >> stations;
     arr_cities = vector<ll>(cities);
    ll dist1 = INT_MAX, dist2 = INT_MAX;
    arr_stations= vector<ll>(stations);

    for (ll i = 0; i < cities; i++){
        cin >> arr_cities[i];
    }
    for (ll i = 0; i < stations; i++){
        cin >> arr_stations[i];
    }
    l = 0;
    r = abs(arr_cities[0] - arr_stations[stations -1]);
    r = max(r, abs(arr_cities[cities -1] - arr_stations[0]));
    while (l < r){
        m = (l + r)/2;
        if (is_possible(m)){
            r = m;
        }else{
            l = m + 1;
        }
    }
    cout << l;
    

}