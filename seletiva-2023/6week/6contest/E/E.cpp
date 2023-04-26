    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    string input;
    int main()
    {
        ios ::sync_with_stdio(0);
        cin.tie(0);

        cin >> input;
        ll len = input.size();
        vector<ll> from_begin(len);
        vector<ll> from_end(len);
        ll counter = 0, aux_cont = 0;
        for (ll i = 0; i < len; i++)
        {
            if (input[i] == 'v')
            {
                from_begin[i] += aux_cont;
                aux_cont++;
                if (i > 0 && input[i-1] != 'v'){
                    from_begin[i] +=  from_begin[i-1];
                }
            }
            else
            {
                aux_cont = 0;
                if (i > 0){
                    from_begin[i] +=  from_begin[i-1];
                }
            }
        }
        counter = 0;
        aux_cont = 0;
        /* for (ll i = len - 1; i >= 0; i--)
        {
            if (input[i] == 'v')
            {
                aux_cont++;
            }
            else
            {
                counter = aux_cont;
                aux_cont = 0;
                from_end[i] = counter;
            }
        } */
        counter = 0;
        for (ll i = 0; i < len; i++)
        {
            if (input[i] == 'o')
            {
                counter += from_begin[i] * from_begin[(len-1)-i];
            }
        }
        cout << counter;
    }