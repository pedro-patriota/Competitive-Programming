#include <bits/stdc++.h>
using namespace std;

long long num_mach, num_products, val, l, r, m;
map<long long, long long> freq_map;
bool is_possible(long long time){
    long long counter = 0;
    auto aut = time;
    for (auto it : freq_map){
        counter += (time/it.first)*it.second;
        if (counter >= num_products){
            return true;
        }
    }
    return false;
};

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    cin >> num_mach;
    cin >> num_products;
    for (long long  i = 0; i < num_mach; i++){
        cin >> val;
        freq_map[val]++;
    }
    l = 0;
    r =  num_products*freq_map.begin()->first;
    auto a = freq_map;
    auto b = r;
    while (l <= r){
        auto left = l;
        auto right = r;
        m = (l + r)/2;
        auto aux = m;
        if (l == r){
            break;
        }
        if (!is_possible(m)){
            l = m + 1;
        }else{
            r = m;
        }
    }
    cout << m;
}