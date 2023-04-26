#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll vertices, edges, p1, p2;
vector<ll> parent;
vector<ll> sizeUF;
vector<bool> seen;

ll find_parent(ll u){
    if (parent[u] == u) return u;
    else parent[u] = find_parent(parent[u]);
}

void uniteSet(ll a, ll b){
    a = find_parent(a);
    b = find_parent(b);
    if (a != b){
        if (sizeUF[a] > sizeUF[b]){
            sizeUF[a] += sizeUF[b];
            parent[b] = a;
        }else{
            sizeUF[b] += sizeUF[a];
            parent[a] = b;

        }
    }
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cin >> vertices >> edges;
    parent = sizeUF = vector<ll> (vertices);
    seen = vector<bool> (vertices, false);
    set <ll> items;
    for (ll i = 0; i < vertices; i++){
        parent[i] = i;
        sizeUF[i] = 1;
    }
    for (ll i = 0; i < edges; i++){
        cin >> p1 >> p2;
        p1--;
        p2--;
        uniteSet(p1, p2);
    }
    ll counter = 0;
    for (ll i = 0; i < vertices; i++){
        if (not seen[find_parent(i)]){
            seen[parent[i]] = true;
            ll aux_size = sizeUF[parent[i]];
            counter += ((aux_size*(aux_size-1))/2);
        }
    }
    if (counter == edges){
        cout << "YES";
    }else{
        cout << "NO";
    }
    
    
}