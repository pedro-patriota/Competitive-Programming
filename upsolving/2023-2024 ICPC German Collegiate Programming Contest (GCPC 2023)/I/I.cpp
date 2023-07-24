    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define endl '\n'

    const ll maxLilipads = 1e6 + 2e5 + 1e4;


    int main()
    {
        ios ::sync_with_stdio(0);
        cin.tie(0);

        ll num_frogs, lilipad, moves, frogId;
        cin >> num_frogs;

        vector<ll> frogs(num_frogs + 1);
        vector<bool> ocuppied (maxLilipads, false);
        set<ll> freeOp;
        for (int i = 1 ; i <= num_frogs; i++){
            cin >> lilipad;
            frogs[i] = lilipad;
            ocuppied[lilipad] = true;        
        }
        for (ll i = 1; i <= num_frogs; i++){
            auto pos = frogs[i];
            //cout << "next " << pos  << endl;
            if (not ocuppied[pos + 1]) {
                freeOp.insert(pos + 1);
            }
        }

        cin >> moves;
        for (ll i = 0; i < moves; i ++){
            cin >> frogId;
            lilipad = frogs[frogId];
            auto it = freeOp.upper_bound(lilipad);
            ll nextLilipad = *it;

            ocuppied[lilipad] = false;
            freeOp.insert(lilipad);

            frogs[frogId] = nextLilipad;
            ocuppied[nextLilipad] = true;
            freeOp.erase(it);


            if (not ocuppied[nextLilipad + 1]) freeOp.insert(nextLilipad + 1);

            cout << nextLilipad << endl;

        }

        return 0;
        
    }