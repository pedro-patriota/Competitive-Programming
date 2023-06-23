    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define endl '\n'

    int main()
    {
        ios ::sync_with_stdio(0);
        cin.tie(0);
        ll n, k,a;
        cin >> n >> k;
        a = 2*n + 1;
        for (ll i = 2*n; i >= 1; i--){
            if (abs(i*i - k) % a == 0){
                cout << i*i << endl;
                break;
            }
        }
        

        
            
        return 0;
        
    }