#include <bits/stdc++.h>
using namespace std;

long long n, k, init_sum, r, l, m, aux, breaks, largest = -1, smallest = 10e10;
const long long MAX_NUMBER = 10e9;
vector<long long>table;

bool is_possible(long long min_val){
    
    aux = 0;
    breaks = 0; 
    for (long long i = 0; i < n; i++){
        aux += table[i];
        if (aux > min_val){
            breaks++;
            aux = table[i];
        }
        if (breaks == k){
            return false;
        }

    }
    return true;
    
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    table.resize(n);
    for (long long i = 0; i < n; i++){
        cin >> table[i];
        if (table[i] > largest){
            largest = table[i];
        }
        if (table[i] < smallest){
            smallest = table[i];
        }
    }

    r = largest*(n - (k -1));
    l = largest;
    while (l < r){
        m = (l+r)/2;
        if (is_possible(m)){
            r = m;
        }else{
            l = m + 1;
        }
    }
    cout << l;

    
}