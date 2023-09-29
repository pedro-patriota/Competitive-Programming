#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    ll q;
    vector<ll> employees(n);
    vector<ll> prefix(n + 1);
    
    for (int i = 0; i < n ; i ++ ) cin >> employees[i];
    sort(employees.begin(), employees.end());

    for (int i = 0; i < n ; i ++){
        prefix[i + 1] = prefix[i] + employees[i];
    }

    for (int i = 0; i < m ;  i++){
        cin >> q;
        int pos = lower_bound(employees.begin(), employees.end(), q) - employees.begin();
        ll actSum = prefix[pos];
        int diff = (n - pos);
        ll newSum = diff*q;

        cout << actSum + newSum << endl;

    }
    
    
        
    return 0;
    
}